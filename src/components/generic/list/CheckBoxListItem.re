[@react.component]
let make =
    (
      ~itemText: React.element,
      ~ischecked: bool,
      ~checkboxClassName: string="",
      ~itemTextClassName: string="",
    ) => {
  <>
    <MaterialUi.ListItemIcon
      classes={MaterialUi.ListItemIcon.Classes.make(~root="root " ++ checkboxClassName, ())}>
      <MaterialUi.Checkbox edge=MaterialUi.Checkbox.Edge.start checked=ischecked color=`Primary />
    </MaterialUi.ListItemIcon>
    <MaterialUi.ListItemText
      primary=itemText
      classes={MaterialUi.ListItemText.Classes.make(~primary=itemTextClassName, ())}
    />
  </>;
};
