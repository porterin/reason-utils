let buildTable = (~className: string, ~children) => (
  <MaterialUi.Table className={className}>
    {children}
  </MaterialUi.Table>
);

[@react.component]
let make = (~className: string, ~children) => buildTable(~className, ~children);
