type t = {
  id: string,
  label: string,
  value: string,
};

let isChecked = (selected: list(string), currentValue: string) => {
  let isSelected = ListUtils.find(selected, value => value == currentValue);
  switch (isSelected) {
  | Some(_isSelected) => true
  | None => false
  };
};

[@react.component]
let make =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~options: list(t),
      ~selected: list(string),
      ~row_layout: bool,
      ~className="",
    ) => {
  <>
    <LabelV4 text=label />
    <div
      className={
        "form-input-checkbox-group " ++ (row_layout ? "u-flex-wrap " : "u-flex__col ") ++ className
      }>
      <>
        {options
         |> List.map((option: t) => {
              <MaterialUi.FormControlLabel
                key={option.id}
                value={MaterialUi.Any(option.value)}
                control={
                  <MaterialUi.Checkbox
                    onChange
                    id={option.id}
                    checked={isChecked(selected, option.value)}
                    classes={MaterialUi.Checkbox.Classes.{
                    "root": Some("form-input-checkbox"),
                    "checked": Some("checked-checkbox"),
                    "colorPrimary": None,
                    "colorSecondary": None,
                    "disabled": None,
                    "indeterminate": None
                  }}
                    color=`Primary
                  />
                }
                label={React.string(option.label)}
                labelPlacement=`End
              />
            })
         |> Array.of_list |> React.array}
      </>
    </div>
  </>;
};
