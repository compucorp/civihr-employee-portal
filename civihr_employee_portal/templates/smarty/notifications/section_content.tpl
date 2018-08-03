<table>
  <tbody>
    {foreach from=$rows item=row}
      <tr>
        <td style="vertical-align:top; width: 125px; padding-bottom:10px;">
          <b>{$row.label}</b>
        </td>
        <td style="vertical-align:top; padding-bottom:10px;">
          {$row.value}
        </td>
      </tr>
    {/foreach}
  </tbody>
</table>
