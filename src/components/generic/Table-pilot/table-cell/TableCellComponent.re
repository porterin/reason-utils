let buildTableCell = (~cell: TableCell.t, ~className: string) => {
  <MaterialUi.TableCell className>
    {
      switch cell {
      | Text(text) => React.string(text);
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
let make = (~cell: TableCell.t, ~className="") => buildTableCell(~cell, ~className);