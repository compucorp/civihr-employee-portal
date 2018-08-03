<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
        "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width">
    <title>{$page_title}</title>
    {literal}
    <style>
        @media only screen {
            html {
                min-height: 100%;
                background: #E8EEF0;
            }
        }

        @media only screen and (max-width: 596px) {
            .small-text-left {
                text-align: left !important;
            }
        }

        @media only screen and (max-width: 596px) {
            table.body img {
                width: auto;
                height: auto;
            }

            table.body center {
                min-width: 0 !important;
            }

            table.body .container {
                width: 95% !important;
            }

            table.body .columns {
                height: auto !important;
                -moz-box-sizing: border-box;
                -webkit-box-sizing: border-box;
                box-sizing: border-box;
                padding-left: 16px !important;
                padding-right: 16px !important;
            }

            table.body .columns .columns {
                padding-left: 0 !important;
                padding-right: 0 !important;
            }

            table.body .collapse .columns {
                padding-left: 0 !important;
                padding-right: 0 !important;
            }

            th.small-12 {
                display: inline-block !important;
                width: 100% !important;
            }

            .columns th.small-12 {
                display: block !important;
                width: 100% !important;
            }
        }

        @media only screen and (max-width: 596px) {
            .email-date {
                line-height: normal !important;
            }
        }

        @media only screen and (max-width: 596px) {
            .request-data-key {
                padding-bottom: 0 !important;
            }
        }

        @media only screen and (min-width: 597px) {
            .request-data .row .columns {
                padding-bottom: 10px !important;
            }
        }
    </style>
    {/literal}
</head>
<body style="-moz-box-sizing: border-box; -ms-text-size-adjust: 100%; -webkit-box-sizing: border-box; -webkit-text-size-adjust: 100%; Margin: 0; box-sizing: border-box; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; line-height: 1.53846; margin: 0; min-width: 100%; padding: 0; text-align: left; width: 100% !important;">

  <table class="body" style="Margin: 0; background: #E8EEF0; border-collapse: collapse; border-spacing: 0; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; height: 100%; line-height: 1.53846; margin: 0; padding: 0; text-align: left; vertical-align: top; width: 100%;">
   <tr style="padding: 0; text-align: left; vertical-align: top;">
      <td class="center" align="center" valign="top" style="-moz-hyphens: auto; -webkit-hyphens: auto; Margin: 0; border-collapse: collapse !important; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; hyphens: auto; line-height: 1.53846; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word;">
         <center class="email" data-parsed="" style="Margin: 40px 0; margin: 40px 0; min-width: 580px; width: 100%;">
            {include file='notifications/title.tpl' title=$title}
            <table align="center" class="container float-center" style="Margin: 0 auto; background: transparent; border-collapse: collapse; border-spacing: 0; float: none; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 580px;">
               <tbody>
                  <tr style="padding: 0; text-align: left; vertical-align: top;">
                     <td style="-moz-hyphens: auto; -webkit-hyphens: auto; Margin: 0; border-collapse: collapse !important; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; hyphens: auto; line-height: 1.53846; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word;">
                        <div class="request">
                           <table class="row collapse" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%;">
                              <tbody>
                                 <tr style="padding: 0; text-align: left; vertical-align: top;">
                                    <th class="small-12 large-12 columns first last" style="Margin: 0 auto; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; line-height: 1.53846; margin: 0 auto; padding: 0; padding-bottom: 16px; padding-left: 0; padding-right: 0; text-align: left; width: 588px;">
                                       <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%;">
                                         {foreach from=$sections item=section}
                                          <tr style="padding: 0; text-align: left; vertical-align: top;">
                                             <th style="Margin: 0; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; line-height: 1.53846; margin: 0; padding: 0; text-align: left;">
                                               {include file='notifications/section.tpl' title=$section.title content=$section.content }
                                             </th>
                                             {include file='notifications/expander.tpl'}
                                          </tr>
                                        {/foreach}
                                       </table>
                                    </th>
                                 </tr>
                              </tbody>
                           </table>
                           <table class="row collapse" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%;">
                              <tbody>
                                 <tr style="padding: 0; text-align: left; vertical-align: top;">
                                    <th class="small-12 large-12 columns first last" style="Margin: 0 auto; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; line-height: 1.53846; margin: 0 auto; padding: 0; padding-bottom: 16px; padding-left: 0; padding-right: 0; text-align: left; width: 588px;">
                                       <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%;">
                                          <tr style="padding: 0; text-align: left; vertical-align: top;">
                                             <th style="Margin: 0; color: #727E8A; font-family: 'Open Sans', 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 13px; font-weight: normal; line-height: 1.53846; margin: 0; padding: 0; text-align: left;">
                                               {include file='notifications/spacer.tpl'}
                                                <img class="text-center email-logo" src="https://civihr.org/sites/default/files/email-logo.png" style="-ms-interpolation-mode: bicubic; Margin: 0 auto; clear: both; display: block; float: none; margin: 0 auto; max-width: 100%; outline: none; text-align: center; text-decoration: none; width: 100px;">
                                             </th>
                                             {include file='notifications/expander.tpl'}
                                          </tr>
                                       </table>
                                    </th>
                                 </tr>
                              </tbody>
                           </table>
                        </div>
                     </td>
                  </tr>
               </tbody>
            </table>
         </center>
      </td>
     </tr>
  </table>
  <!-- prevent Gmail on iOS font size manipulation -->
  <div style="display:none; white-space:nowrap; font:15px courier; line-height:0;">
    &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
  </div>

</body>
</html>
