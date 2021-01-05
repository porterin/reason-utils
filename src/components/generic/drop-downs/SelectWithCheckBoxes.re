type t = {
  key: string,
  value: string,
  text: string,
};

let isChecked = (selected: list(string), currentValue: string) => {
  List.exists((a: string) => a === currentValue, selected);
};

let getListToString = (a: list(string)): string => {
  let rec join = (lst, delimeter) => {
    switch (lst) {
    | [] => ""
    | [head] => head
    | [head, ...tail] => head ++ ", " ++ join(tail, delimeter)
    };
  };
  let concatString = join(a, "");
  String.length(concatString) > 30 ? String.sub(concatString, 0, 30) ++ "..." : concatString;
  //TODO Dwarika: We need to make concatString configurable
};

[@react.component]
let make =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~selected: list(string),
      ~items: list(t),
      ~renderValue: option(list(string) => string),
    ) => {
  <MaterialUi.FormControl variant=`Outlined className="form-input-select">
    <MaterialUi.InputLabel id="select-checkbox-label-id" htmlFor="select-checkbox-label">
      label->React.string
    </MaterialUi.InputLabel>
    <MaterialUi.Select
      labelId="select-checkbox-label-id"
      label={React.string(label)}
      multiple=true
      value={`Array(selected |> Array.of_list)}
      onChange={(event, _) => onChange(event)}
      renderValue={(selected: array(string)) =>
        switch (renderValue) {
        | None => getListToString(selected |> Array.to_list)
        | Some(fn) => fn(selected |> Array.to_list)
        }
      }>
      {items
       |> List.map(item =>
            <MaterialUi.MenuItem key={item.key} value={`String(item.value)}>
              <MaterialUi.Checkbox
                classes=[Root("form-input-checkbox"), Checked("checked-checkbox")]
                value={item.value}
                checked={isChecked(selected, item.value)}
              />
              <MaterialUi.ListItemText primary={React.string(item.text)} />
            </MaterialUi.MenuItem>
          )
       |> ReasonReactUtils.listToReactArray}
    </MaterialUi.Select>
  </MaterialUi.FormControl>;
};
