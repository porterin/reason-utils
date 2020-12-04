[@react.component]
let make =
    (
      ~selected: bool=false,
      ~onClick: unit => unit=ignore,
      ~className: string="",
      ~children: React.element,
    ) => {
  <MaterialUi.ListItem
    onClick={_ => onClick()}
    className={(selected ? "list-item-selected " : "list-item ") ++ className}>
    children
  </MaterialUi.ListItem>;
};
