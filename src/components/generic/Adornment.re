type position = [ | `Start | `End];

[@react.component]
let make = (~position: position=`Start, ~className: string="", ~children: React.element) => {
  <MaterialUi.InputAdornment position className> children </MaterialUi.InputAdornment>;
};
