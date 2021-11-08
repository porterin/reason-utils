[@react.component]
let make =
    (~is_selected: bool=false, ~onClick: bool => unit, ~class_name: string="", ~text: string) => {
  let checkBoxItems: list(CheckBoxGroup.t) = [{id: "0", value: text, label: text}];

  <FormInput.CheckBox
    input_props={FormInput.make_props(
      ~className=class_name,
      ~label="",
      ~onChange=_ => onClick(!is_selected),
      ~result=None,
      (),
    )}
    checkbox_props={
      selected: is_selected ? [List.hd(checkBoxItems).value] : [],
      options: checkBoxItems,
      row_layout: true,
    }
  />;
};
