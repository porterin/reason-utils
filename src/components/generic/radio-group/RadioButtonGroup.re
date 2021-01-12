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
    <MaterialUi.RadioGroup
      row className="form-radio-button-group" value={MaterialUi_Types.Any(value)} onChange>
      {options
       |> List.mapi((index: int, button: t) => {
            <MaterialUi.FormControlLabel
              key={string_of_int(index)}
              value={MaterialUi_Types.Any(button.value)}
              control={
                <MaterialUi.Radio
                  classes={MaterialUi.Radio.Classes.make(
                    ~root="form-input-radio-button",
                    ~checked="checked-radio-button",
                    (),
                  )}
                  color=`Primary
                />
              }
              label={React.string(button.label)}
            />
          })
       |> ReasonReactUtils.listToReactArray}
    </MaterialUi.RadioGroup>
  </>;
};
