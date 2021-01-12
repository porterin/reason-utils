let buildList = (~className: string, ~children) =>
  <MaterialUi.List className> children </MaterialUi.List>;

[@react.component]
let make = (~className: string="", ~children) =>
  buildList(~className, ~children);
