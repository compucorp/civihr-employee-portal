(function($) {

Drupal.theme.prototype.ctools_custom_modal_html = function () {
    var html = '';

    html += '<div id=ctools-modal">';
    html += '<div class="modal show">';
    html += '   <div class="modal-dialog">';
    html += '       <div class="modal-content">';
    html += '           <div class="modal-header">';
    html += '               <button type="button" class="close ctools-close-modal" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
    html += '               <h4 id="modal-title" class="modal-title">Modal title</h4>';
    html += '           </div>';
    html += '           <div id="modal-content">';
    html += '               <div class="modal-body">';
    html += '               </div>';
    html += '           </div>';
    html += '       </div>';
    html += '   </div>';
    html += '</div>';

    return html;
};

Drupal.behaviors.civihr_employee_portal = {
    attach: function (context, settings) {

        $(window).load(function(){
            $('a.ctools-use-modal').each( function() {
                var $this = $(this);
                $this.unbind();
                $this.click(Drupal.CTools.Modal.clickAjaxLink);
                var element_settings = {};
                if ($this.attr('href')) {
                  element_settings.url = $this.attr('href');
                  element_settings.event = 'click';
                  element_settings.progress = {
                    type: 'throbber'
                  };
                }
                var base = $this.attr('href');
                Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
            });
        });
    }
}
})(jQuery);
