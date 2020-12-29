type t = {
  key: string,
  value: string,
  text: string,
};

let defaultSelectItem: t = {key: "Select", value: "", text: "None"};

let getSelectedItem = (value: string, options: list(t)): option(t) => {
  List.exists((a: t) => a.value === value, options)
    ? Some(options |> List.find((item: t) => {item.value === value})) : None;
};

[@react.component]
let make =
    (~label: string, ~onChange: ReactEvent.Form.t => unit, ~value: option(t), ~items: list(t)) => {
  let selectedValue = Belt.Option.getWithDefault(value, defaultSelectItem);

  <MaterialUi.FormControl variant=`Outlined className="form-input-select">
    <MaterialUi.InputLabel id="select-label-id" htmlFor="select-label">
      label->React.string
    </MaterialUi.InputLabel>
    <MaterialUi.Select
      labelId="select-label-id"
      label={React.string(label)}
      defaultValue={defaultSelectItem.value}
      value={`String(selectedValue.value)}
      onChange={(e, _) => onChange(e)}>
      <MaterialUi.MenuItem value={`String(defaultSelectItem.value)}>
        defaultSelectItem.text->React.string
      </MaterialUi.MenuItem>
      {items
       |> List.map(item =>
            <MaterialUi.MenuItem key={item.key} value={`String(item.value)}>
              {React.string(item.text)}
            </MaterialUi.MenuItem>
          )
       |> ReasonReactUtils.listToReactArray}
    </MaterialUi.Select>
  </MaterialUi.FormControl>;
};
