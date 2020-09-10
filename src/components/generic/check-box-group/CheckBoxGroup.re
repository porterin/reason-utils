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
                  <CheckBox
                    onChange
                    id={option.id}
                    checked={isChecked(selected, option.value)}
                    rootClassName="form-input-checkbox"
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
