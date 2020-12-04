let buildTableRow = (~className: string, ~children) => {
  <MaterialUi.TableRow className={className}>
    {children}
  </MaterialUi.TableRow>
};

[@react.component]
let make = (~className: string, ~children) => buildTableRow(~className, ~children);