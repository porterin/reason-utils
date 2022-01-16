let buildTableRow = (~className: string, ~children, ~onClick, ~onMouseEnter, ~onMouseLeave) => {
  <MaterialUiTableRowV2 className onClick onMouseEnter onMouseLeave>
    children
  </MaterialUiTableRowV2>;
};

[@react.component]
let make =
    (
      ~className: string,
      ~onClick: ReactEvent.Mouse.t => unit=_ => (),
      ~onMouseEnter: ReactEvent.Mouse.t => unit=_ => (),
      ~onMouseLeave: ReactEvent.Mouse.t => unit=_ => (),
      ~children,
    ) =>
  buildTableRow(~className, ~onClick, ~onMouseEnter, ~onMouseLeave, ~children);
