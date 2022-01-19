let buildTableCell = (~cell: TableCell.t, ~colSpan: int, ~className: string, ~is_visible: bool) => {
  <MaterialUi.TableCell className colSpan>
    {is_visible
       ? switch (cell) {
         | Date({format, date}) => Date.toString(~format, ~date)->React.string
         | Text(text) => React.string(text)
         | Status({color, text}) =>
           <span className={color->ColorPalette.getClassName}> {React.string(text)} </span>
         | ActionButton(text, callback) =>
           <TertiaryButton onSelectCB={() => callback()}> {React.string(text)} </TertiaryButton>
         | Custom(renderFn) => renderFn()
         | RedirectLink(title, link) => <RedirectLinkComponent title link />
         }
       : React.null}
  </MaterialUi.TableCell>;
};

[@react.component]
let make = (~cell: TableCell.t, ~className="", ~colSpan: int=1, ~is_visible: bool=true) =>
  buildTableCell(~cell, ~colSpan, ~className, ~is_visible);
