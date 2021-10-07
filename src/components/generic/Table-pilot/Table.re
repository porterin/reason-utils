let buildTable = (~className: string, ~children, ~is_sticky_header) => {
  <MaterialUi.Table className stickyHeader=is_sticky_header> children </MaterialUi.Table>;
};

[@react.component]
let make = (~className: string, ~is_sticky_header: bool=false, ~children) =>
  buildTable(~className, ~is_sticky_header, ~children);
