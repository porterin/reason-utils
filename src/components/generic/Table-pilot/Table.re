let buildTable = (~className: string, ~children, ~stickyHeader) => {
  <MaterialUi.Table className={className} stickyHeader>
    {children}
  </MaterialUi.Table>
};

[@react.component]
let make = (~className: string, ~stickyHeader: bool=false, ~children) => buildTable(~className, ~stickyHeader, ~children);
