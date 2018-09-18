<p>
  <a href="{$profileLink}">{$displayName} - {$workEmail}</a><br/>
  Submitted on: {$submissionDate}<br/>
  The following information was submitted via "{$webformTitle}"
</p>

{foreach from=$submittedValues key=pageTitle item=pageValues}
  {* Most webforms don't have separate pages, so don't non-numeric page titles *}
  {if !is_numeric($pageTitle)}
    <h3>{$pageTitle}</h3>
  {/if}
  <p>
  {foreach from=$pageValues key=fieldsetLabel item=fieldSetValues}
    {if !is_numeric($fieldsetLabel)}
      <h4>{$fieldsetLabel}</h4>
    {/if}
    {foreach from=$fieldSetValues key=label item=value}
      {$label}: {$value}<br/>
    {/foreach}
  {/foreach}
  </p>
{/foreach}
