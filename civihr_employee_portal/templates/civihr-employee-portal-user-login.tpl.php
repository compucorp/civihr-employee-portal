<?php
drupal_session_start();
$customLoginSuccessMessage = _drupal_session_read('custom_login_success_message');
_drupal_session_write('custom_login_success_message', '');

$errors = form_get_errors();
?>
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
<div class="pane-user-login-forgot-password hidden">
    <div class="row">
        <div class="col-xs-12">
            <p>Enter your work email address in the box below and we'll resend you username and password.</p>
            <?php print drupal_render($form['forgot-password']); ?>
            <?php if (!$customLoginSuccessMessage): ?>
                <div class="form-actions form-wrapper" id="edit-actions">
                    <input name="forgot-password-button" value="Send me my details" class="form-submit btn btn-default btn-primary" type="submit">
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
<script type="text/javascript">
    (function($){
        $(document).ready(function(){
            var $panelForgotPassword  = $('.pane-user-login-forgot-password');
            $('#link-forgot-password').click(function(e){
                $panelForgotPassword.toggleClass('hidden');
                e.stopImmediatePropagation();
                return false;
            });

        });
    }(CRM.$));
</script>