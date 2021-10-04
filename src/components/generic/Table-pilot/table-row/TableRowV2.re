let buildTableRow = (~className: string, ~children, ~onClick) => {
  <MaterialUiTableRowV2 className onClick> children </MaterialUiTableRowV2>;
};

[@react.component]
let make = (~className: string, ~onClick: ReactEvent.Mouse.t => unit=_ => (), ~children) =>
  buildTableRow(~className, ~onClick, ~children);
