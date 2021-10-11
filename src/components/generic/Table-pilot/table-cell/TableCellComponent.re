let buildTableCell = (~cell: TableCell.t,  ~colSpan: int, ~className: string,) => {
  <MaterialUi.TableCell className colSpan>
    {
      switch cell {
      | Date({format, date}) => Date.toString(~format, ~date) -> React.string;
      | Text(text) => React.string(text);
      | Status({color, text}) => <span className=(color ->ColorPalette.getClassName)>(React.string(text))</span>;
      | ActionButton(text, callback) => (
        <TertiaryButton
          onSelectCB={() => callback()}>
          {React.string(text)}
        </TertiaryButton>
      )
      | Custom(renderFn) => renderFn()
      | RedirectLink(title, link) => <RedirectLinkComponent title link />
      };
    }
  </MaterialUi.TableCell>
};

[@react.component] 
let make = (~cell: TableCell.t, ~className="",  ~colSpan: int=1) => buildTableCell(~cell, ~colSpan, ~className);
