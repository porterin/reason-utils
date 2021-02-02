[@react.component]
let make = (~className: string, ~children: React.element) => {
  <div className={"form-input-container " ++ className}> children </div>;
};
