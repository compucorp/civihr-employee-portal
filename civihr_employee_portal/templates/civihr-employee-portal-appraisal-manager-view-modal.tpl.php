<div class="form-item form-group appraisal-manager-view-modal modal-civihr-custom__section form-horizontal">
    <div class="form-item form-group">
        <div class="col-md-4"><label><?php print $appraisalCycle['cycle_name']; ?></label></div>
        <div class="col-md-4"><label><?php print t('Cycle ID'); ?>:</label> <?php print $appraisalCycle['id']; ?></div>
        <div class="col-md-4"><label><?php print t('Period'); ?>:</label> <?php print $appraisalCycle['cycle_start_date']; ?> - <?php print $appraisalCycle['cycle_end_date']; ?></div>
    </div>
    <hr>

    <div class="form-item form-group">
        <div class="col-md-5"><label><?php print t('Self Appraisal Due'); ?>:</label></div>
        <div class="col-md-7"><?php print $appraisal['self_appraisal_due']; ?></div>
    </div>
    <div class="form-item form-group">
        <div class="col-md-5"><label><?php print t('Manager Appraisal Due'); ?>:</label></div>
        <div class="col-md-7"><?php print $appraisal['manager_appraisal_due']; ?></div>
    </div>
    <div class="form-item form-group">
        <div class="col-md-5"><label><?php print t('Grade Due'); ?>:</label></div>
        <div class="col-md-7"><?php print $appraisal['grade_due']; ?></div>
    </div>
    <hr/>
<?php if (!empty($documents)): ?>
    <div class="form-item form-group documents">
        <label class="col-md-3"><?php print t('Documents'); ?>:</label>
        <?php foreach ($documents as $document): ?>
            <div class="form-item form-group">
                <div class="col-md-1">&nbsp;</div>
                <div class="col-md-4"><?php print $document['appraisalFileTypeLabel']; ?></div>
                <div class="col-md-4"><a href="<?php print $document['url']; ?>" target="_blank"><?php print $document['name']; ?></a></div>
                <div class="col-md-3"><?php print format_size($document['fileSize']); ?></div>
            </div>
        <?php endforeach; ?>
    </div>
    <hr/>
<?php endif; ?>


<?php if (!empty($appraisal['notes'])): ?>
    <div class="form-item form-group notes">
        <div class="col-md-4"><?php print t('Manager Notes'); ?>:</div>
        <div class="col-md-8"><?php print $appraisal['notes']; ?></div>
    </div>
    <hr/>
<?php endif; ?>

    <div class="form-item form-group">
        <div class="col-md-8"><?php print t('Appraisal meeting date'); ?>:</div>
        <div class="col-md-4"><?php print $appraisal['meeting_date']; ?></div>
    </div>
    <div class="form-item form-group">
        <div class="col-md-8"><?php print t('Appraisal meeting completed'); ?>:</div>
        <div class="col-md-4"><?php print $appraisal['meeting_completed'] ? t('Yes') : t('No'); ?></div>
    </div>
    <div class="form-item form-group">
        <div class="col-md-8"><?php print t('Discussed and approved by employee'); ?>:</div>
        <div class="col-md-4"><?php print $appraisal['approved_by_employee'] ? t('Yes') : t('No'); ?></div>
    </div>
</div>