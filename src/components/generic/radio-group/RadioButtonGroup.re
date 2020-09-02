type t = {
  label: string,
  value: string,
};

[@react.component]
let make =
    (
      ~label: string,
      ~options: list(t),
      ~value: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~row: bool,
    ) => {
  <>
    <LabelV4 text=label />
    <MaterialUi.RadioGroup row className="form-radio-button-group" value={MaterialUi.Any(value)} onChange>
      {options
       |> List.mapi((index: int, button: t) => {
            <MaterialUi.FormControlLabel
              key={string_of_int(index)}
              value={MaterialUi.Any(button.value)}
              control={
                <MaterialUi.Radio
                  classes={MaterialUi.Radio.Classes.{
                    "root": Some("form-input-radio-button"),
                    "checked": Some("checked-radio-button"),
                    "colorPrimary": None,
                    "colorSecondary": None,
                    "disabled": None
                  }}
                  color=`Primary
                />
              }
              label={React.string(button.label)}
            />
          })
       |> Array.of_list |> React.array}
    </MaterialUi.RadioGroup>
  </>;
};
