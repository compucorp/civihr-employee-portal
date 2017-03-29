<?php
use Yoti\ActivityDetails;
use Yoti\YotiClient;

require_once __DIR__ . '/sdk/boot.php';

/**
 * Class YotiConnectHelper
 *
 * @package Drupal\yoti_connect
 *
 */
class YotiConnectHelper
{
    /**
     * @var array
     */
    public static $profileFields = array(
        ActivityDetails::ATTR_SELFIE => 'Selfie',
        ActivityDetails::ATTR_PHONE_NUMBER => 'Phone number',
        ActivityDetails::ATTR_DATE_OF_BIRTH => 'Date of birth',
        ActivityDetails::ATTR_GIVEN_NAMES => 'Given names',
        ActivityDetails::ATTR_FAMILY_NAME => 'Family name',
        ActivityDetails::ATTR_NATIONALITY => 'Nationality',
        'gender' => 'Gender',
        'email_address' => 'Email Address',
    );

    /**
     * Running mock requests instead of going to yoti
     * @return bool
     */
    public static function mockRequests()
    {
        return defined('YOTI_MOCK_REQUEST') && YOTI_MOCK_REQUEST;
    }

    /**
     * @return bool
     */
    public function link()
    {
        global $user;

        $currentUser = $user;
        $config = self::getConfig();
//    print_r($config);exit;
        $token = (!empty($_GET['token'])) ? $_GET['token'] : NULL;

        // if no token then ignore
        if (!$token) {
            $this->setFlash('Could not get Yoti token.', 'error');

            return FALSE;
        }

        // init yoti client and attempt to request user details
        try {
            $yotiClient = new YotiClient($config['yoti_sdk_id'], $config['yoti_pem']['contents']);
            $yotiClient->setMockRequests(self::mockRequests());
            $activityDetails = $yotiClient->getActivityDetails($token);
        }
        catch (Exception $e) {
            $this->setFlash('Yoti could not successfully connect to your account.', 'error');

            return FALSE;
        }

        // if unsuccessful then bail
        if ($yotiClient->getOutcome() != YotiClient::OUTCOME_SUCCESS) {
            $this->setFlash('Yoti could not successfully connect to your account.', 'error');

            return FALSE;
        }

        // check if yoti user exists
        $drupalYotiUid = $this->getDrupalUid($activityDetails->getUserId());

        // if yoti user exists in db but isn't linked to a drupal account (orphaned row) then delete it
        if ($drupalYotiUid && $currentUser && $currentUser->uid != $drupalYotiUid && !user_load($drupalYotiUid)) {
            // remove users account
            $this->deleteYotiUser($drupalYotiUid);
        }

        // if user isn't logged in
        if (!$currentUser->uid) {

            // register new user
            if (!$drupalYotiUid) {
                $errMsg = NULL;

                // attempt to get their user id by email passed from yoti
                if (!empty($config['connect_email'])) {
                    if (($email = $activityDetails->getProfileAttribute('email_address'))) {
                        $byMail = user_load_by_mail($email);
                        if ($byMail) {
                            $drupalYotiUid = $byMail->uid;
                            $this->createYotiUser($drupalYotiUid, $activityDetails);
                        }
                    }
                }

                // create new user if option is enabled
                if (!$drupalYotiUid) {
                    if (empty($config['only_existing'])) {
                        try {
                            $drupalYotiUid = $this->createUser($activityDetails);
                        }
                        catch (Exception $e) {
                            $errMsg = $e->getMessage();
                        }
                    }
                    else {
                        $errMsg = "Drupal user doesn't exist";
                    }
                }

                // no user id? no account
                if (!$drupalYotiUid) {
                    // if couldn't create user then bail
                    $this->setFlash("Could not create user account. $errMsg", 'error');

                    return FALSE;
                }
            }

            // log user in
            $this->loginUser($drupalYotiUid);
        }
        else {
            // if current logged in user doesn't match yoti user registered then bail
            if ($drupalYotiUid && $currentUser->uid != $drupalYotiUid) {
                $this->setFlash('This Yoti account is already linked to another account.', 'error');
            }
            // if joomla user not found in yoti table then create new yoti user
            elseif (!$drupalYotiUid) {
                $this->createYotiUser($currentUser->uid, $activityDetails);
                $this->setFlash('Your Yoti account has been successfully linked.');
            }
        }

        return TRUE;
    }

    /**
     * Unlink account from currently logged in
     */
    public function unlink()
    {
        global $user;

        // unlink
        if ($user) {
            $this->deleteYotiUser($user->uid);
            return TRUE;
        }

        return FALSE;
    }

    /**
     * @param $message
     * @param string $type
     */
    private function setFlash($message, $type = 'status')
    {
        drupal_set_message($message, $type);
    }

    /**
     * @param string $prefix
     * @return string
     */
    private function generateUsername($prefix = 'yoticonnect-')
    {
        // generate username
        $i = 0;
        do {
            $username = $prefix . $i++;
        }
        while (user_load_by_name($username));

        return $username;
    }

    /**
     * @param $prefix
     * @param string $domain
     * @return string
     */
    private function generateEmail($prefix = 'yoticonnect-', $domain = 'example.com')
    {
        // generate email
        $i = 0;
        do {
            $email = $prefix . $i++ . "@$domain";
        }
        while (user_load_by_mail($email));

        return $email;
    }

    /**
     * @param int $length
     * @return string
     */
    private function generatePassword($length = 10)
    {
        // generate password
        $alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';
        $password = ''; //remember to declare $pass as an array
        $alphaLength = strlen($alphabet) - 1; //put the length -1 in cache
        for ($i = 0; $i < $length; $i++) {
            $n = rand(0, $alphaLength);
            $password .= $alphabet[$n];
        }

        return $password;
    }

    /**
     * @param ActivityDetails $activityDetails
     * @return int
     * @throws Exception
     */
    private function createUser(ActivityDetails $activityDetails)
    {
        $user = array(
            'status' => 1,
            //            'roles' => array(
            //                DRUPAL_AUTHENTICATED_RID => 'authenticated user',
            //                3 => 'custom role',
            //            ),
        );

        //Mandatory settings
        $user['pass'] = $this->generatePassword();
        $user['mail'] = $user['init'] = $this->generateEmail();
        $user['name'] = $this->generateUsername();//This username must be unique and accept only a-Z,0-9, - _ @ .

        // The first parameter is sent blank so a new user is created.
        $user = user_save('', $user);

        // set new id
        $userId = $user->uid;
        $this->createYotiUser($userId, $activityDetails);

        return $userId;
    }

    /**
     * @param $yotiId
     * @return int
     */
    private function getDrupalUid($yotiId, $field = "identifier")
    {
        $tableName = self::tableName();
        $col = db_query("SELECT uid FROM `{$tableName}` WHERE `{$field}` = '$yotiId'")->fetchCol();
        return ($col) ? reset($col) : NULL;
    }

    /**
     * @param $userId
     * @param ActivityDetails $activityDetails
     */
    private function createYotiUser($userId, ActivityDetails $activityDetails)
    {
        //        $user = user_load($userId);
        $meta = $activityDetails->getProfileAttribute();
        unset($meta[ActivityDetails::ATTR_SELFIE]); // don't save selfie to db

        $selfieFilename = NULL;
        if (($content = $activityDetails->getProfileAttribute(ActivityDetails::ATTR_SELFIE))) {
            $uploadDir = self::uploadDir();
            if (!is_dir($uploadDir)) {
                drupal_mkdir($uploadDir, 0777, TRUE);
            }

            $selfieFilename = md5("selfie" . time()) . ".png";
            file_put_contents("$uploadDir/$selfieFilename", $content);
            //      file_put_contents(self::uploadDir() . "/$selfieFilename", $activityDetails->getUserProfile('selfie'));
            $meta['selfie_filename'] = $selfieFilename;
        }

        //        foreach (self::$profileFields as $param => $label)
        //        {
        //            $meta[$param] = $activityDetails->getProfileAttribute($param);
        //        }
        //unset($meta[ActivityDetails::ATTR_SELFIE]); // don't save selfie to db

        db_insert(self::tableName())->fields(array(
            'uid' => $userId,
            'identifier' => $activityDetails->getUserId(),
            'phone_number' => $activityDetails->getProfileAttribute(ActivityDetails::ATTR_PHONE_NUMBER),
            'date_of_birth' => $activityDetails->getProfileAttribute(ActivityDetails::ATTR_DATE_OF_BIRTH),
            'given_names' => $activityDetails->getProfileAttribute(ActivityDetails::ATTR_GIVEN_NAMES),
            'family_name' => $activityDetails->getProfileAttribute(ActivityDetails::ATTR_FAMILY_NAME),
            'nationality' => $activityDetails->getProfileAttribute(ActivityDetails::ATTR_NATIONALITY),
            'gender' => $activityDetails->getProfileAttribute('gender'),
            'email_address' => $activityDetails->getProfileAttribute('email_address'),
            'selfie_filename' => $selfieFilename,
            'data' => serialize($meta),
        ))->execute();
    }

    /**
     * @param int $userId joomla user id
     */
    private function deleteYotiUser($userId)
    {
        db_delete(self::tableName())->condition("uid", $userId)->execute();
    }

    /**
     * @param $userId
     */
    private function loginUser($userId)
    {
        //        $user = user_load($userId);
        //        var_dump($user);exit;
        //        user_login_finalize($user);
        $form_state['uid'] = $userId;
        user_login_submit(array(), $form_state);
    }

    /**
     * not used in this instance
     * @return string
     */
    public static function tableName()
    {
        return 'users_yoti';
    }

    /**
     * @param bool $realPath
     * @return string
     */
    public static function uploadDir($realPath = TRUE)
    {
        return ($realPath) ? drupal_realpath("yoti://") : 'yoti://';
    }

    /**
     * @return string
     */
    public static function uploadUrl()
    {
        return file_create_url(self::uploadDir());
    }

    /**
     * @return array
     */
    public static function getConfig()
    {
        $pem = variable_get('yoti_pem');
        $name = $contents = NULL;
        if ($pem) {
            $file = file_load($pem);
            $name = $file->uri;
            $contents = file_get_contents(drupal_realpath($name));
        }
        $config = array(
            'yoti_app_id' => variable_get('yoti_app_id'),
            'yoti_sdk_id' => variable_get('yoti_sdk_id'),
            'only_existing' => variable_get('only_existing'),
            'yoti_success_url' => variable_get('yoti_success_url', '/user'),
            'yoti_fail_url' => variable_get('yoti_fail_url', '/'),
            'connect_email' => variable_get('connect_email'),
            'yoti_pem' => array(
                'name' => $name,
                'contents' => $contents,
            ),
        );

        if (self::mockRequests()) {
            $config = array_merge($config, require_once __DIR__ . '/sdk/sample-data/config.php');
        }

        return $config;
    }

    /**
     * @return null|string
     */
    public static function getLoginUrl()
    {
        $config = self::getConfig();
        if (empty($config['yoti_app_id'])) {
            return NULL;
        }

        //https://staging0.www.yoti.com/connect/ad725294-be3a-4688-a26e-f6b2cc60fe70
        //https://staging0.www.yoti.com/connect/990a3996-5762-4e8a-aa64-cb406fdb0e68

        return YotiClient::getLoginUrl($config['yoti_app_id']);
    }
}