<?php
drupal_session_start();
$customLoginSuccessMessage = _drupal_session_read('custom_login_success_message');
_drupal_session_write('custom_login_success_message', '');

$errors = form_get_errors();
?>
<div class="panel panel-login">
    <div class="panel-heading">
        <h2 class="panel-title">Login:</h2>
    </div>
    <div class="panel-body">
        <?php if ($errors): ?>
            <div class="row" id="messages">
                <div class="alert alert-danger alert-dismissable">
                    <?php /*<button type="button" class="close" data-dismiss="alert" aria-hidden="true">×</button>*/ ?>
                    <ul>
                        <?php foreach ($errors as $error): ?>
                            <li><?php print $error; ?></li>
                        <?php endforeach; ?>
                    </ul>
                </div>
            </div>
        <?php endif; ?>
        <div class="row">
            <div class="col-xs-12">
                <?php print drupal_render($form['name']); ?>
                <?php print drupal_render($form['pass']); ?>
                <?php print drupal_render($form['form_build_id']); ?>
                <?php print drupal_render($form['form_id']); ?>
                <?php print drupal_render($form['actions']); ?>
            </div>
        </div>
    </div>
</div>
<div class="panel panel-forgot-password hidden">
    <div class="panel-body">
        <div class="row">
            <div class="col-xs-12">
                <p>Enter your work email address in the box below and we'll resend you username and password.</p>
                <?php print drupal_render($form['forgot-password']); ?>
                <?php if (!$customLoginSuccessMessage): ?>
                    <div class="form-actions form-wrapper" id="edit-actions">
                        <input name="forgot-password-button" value="Send me my details" class="form-submit btn btn-default btn-primary" type="button">
                    </div>
                <?php endif; ?>
            </div>
        </div>
        <?php if ($customLoginSuccessMessage): ?>
        <div class="row">
            <div class="alert alert-success text-center">
                <ul>
                    <li><?php print $customLoginSuccessMessage; ?></li>
                </ul>
            </div>
        </div>
        <?php endif; ?>
    </div>
</div>
<div class="row">
    <div class="col-xs-12">
        <p class="text-center"><?php print t('Don\'t have a login?'); ?><br/>
        <a href="/request_new_account/nojs" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed" title="<?php print t('Request new account'); ?>"><?php print t('Click here to request one from your HR administrator'); ?></a></p>
    </div>
</div>
<script type="text/javascript">
    (function($){
        $(document).ready(function(){

            $('#messages').hide();
            $('#block-system-main').hide();
            $('#block-system-navigation').hide();
            $('#page-header').hide();


            var $panelForgotPassword  = $('.panel-forgot-password');
            $('#link-forgot-password').click(function(e){
                $panelForgotPassword.toggleClass('hidden');
                e.stopImmediatePropagation();
                return false;
            });

        });
    }(CRM.$));
</script>