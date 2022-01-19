let buildTableBody = (~className: string, ~children) => {
  <MaterialUi.TableBody className={className}>
    {children}
  </MaterialUi.TableBody>
};

[@react.component]
let make = (~className: string, ~children) => buildTableBody(~className, ~children);