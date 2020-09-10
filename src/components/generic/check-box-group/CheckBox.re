[@react.component]
let make = (~id: string, ~onChange: ReactEvent.Form.t => unit, ~checked: bool, ~rootClassName: string="") => {
  <MaterialUi.Checkbox
    onChange
    id
    checked
    classes=MaterialUi.Checkbox.Classes.{
      "root": Some(rootClassName),
      "checked": Some("checked-checkbox"),
      "colorPrimary": None,
      "colorSecondary": None,
      "disabled": None,
      "indeterminate": None,
    }
    color=`Primary
  />;
};
