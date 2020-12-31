open Belt;
type result('a, 'b) = Result.t('a, 'b);
let error = err => Result.Error(err);

type formInput =
  | Input(string)
  | Date({
      value: Js.Date.t,
      minDate: option(Js.Date.t),
      maxDate: option(Js.Date.t),
      onChange: Js.Date.t => unit,
      format: string,
    })
  | DateTime({
      value: option(Js.Date.t),
      minDate: option(Js.Date.t),
      maxDate: option(Js.Date.t),
      onChange: Js.Date.t => unit,
      format: string,
      onClear: unit => unit,
    })
  | Time({
      value: Js.Date.t,
      onChange: Js.Date.t => unit,
    })
  | KeyInputTime({
      value: Js.Date.t,
      onChange: Js.Date.t => unit,
      format: string,
      invalidDateMessage: option(string),
    })
  | RadioGroup({
      options: list(RadioButtonGroup.t),
      value: string,
      row_layout: bool,
    })
  | Select({
      value: option(SelectComponent.t),
      items: list(SelectComponent.t),
    })
  | CheckBox({
      selected: list(string),
      options: list(CheckBoxGroup.t),
      row_layout: bool,
    })
  | SelectCheckBoxes({
      selected: list(string),
      options: list(SelectWithCheckBoxes.t),
      renderValue: option(list(string) => string),
    });

type props('b, 'c) = {
  label: string,
  onChange: ReactEvent.Form.t => unit,
  isDisabled: bool,
  placeholder: string,
  value: formInput,
  result: option(Belt.Result.t('b, 'c)),
  onBlur: unit => unit,
  warning: ReactEvent.Form.t => option(string),
  className: string,
};

let make_props =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~isDisabled: bool=false,
      ~placeholder="",
      ~value: formInput,
      ~onBlur: unit => unit=() => (),
      ~result: option(Belt.Result.t('b, 'c)),
      ~warning=_ => None,
      ~className="",
      (),
    ) => {
  label,
  onChange,
  isDisabled,
  placeholder,
  onBlur,
  value,
  result,
  warning,
  className,
};

let getWarningOrError =
    (warning: option(string), result: option(result('a, 'b))): React.element => {
  <div className="input-error-container">
    {switch (result) {
     | None =>
       switch (warning) {
       | None => React.null
       | Some(warning) => <div className="warning"> {React.string(warning)} </div>
       }
     | Some(result) =>
       switch (result) {
       | Error(err) => <div className="error"> {React.string(err)} </div>
       | _ => React.null
       }
     }}
  </div>;
};

[@react.component]
let make = (~input_props: props('b, 'c)) => {
  let (warning, setWarning) = React.useState(_ => None);
  <div className={"form-input-container " ++ input_props.className}>
    {switch (input_props.value) {
     | Date(date_params) =>
       <DatePicker
         label={input_props.label}
         disabled={input_props.isDisabled}
         onChange={date => date_params.onChange(date |> MomentRe.Moment.toDate)}
         value={date_params.value |> MomentRe.momentWithDate}
         minDate={Belt.Option.mapWithDefault(date_params.minDate, None, v =>
           Some(v |> MomentRe.momentWithDate)
         )}
         maxDate={Belt.Option.mapWithDefault(date_params.maxDate, None, v =>
           Some(v |> MomentRe.momentWithDate)
         )}
         format={date_params.format}
       />
     | DateTime(date_params) =>
       <DateTimePicker
         label={input_props.label}
         onChange={date => date_params.onChange(date |> MomentRe.Moment.toDate)}
         value={Belt.Option.mapWithDefault(date_params.value, None, date =>
           Some(date |> MomentRe.momentWithDate)
         )}
         minDate={Belt.Option.mapWithDefault(date_params.minDate, None, v =>
           Some(v |> MomentRe.momentWithDate)
         )}
         maxDate={Belt.Option.mapWithDefault(date_params.maxDate, None, v =>
           Some(v |> MomentRe.momentWithDate)
         )}
         onClear={date_params.onClear}
       />

     | Time(time_params) =>
       <TimePicker
         label={input_props.label}
         disabled={input_props.isDisabled}
         onChange={date => time_params.onChange(date |> MomentRe.Moment.toDate)}
         value={time_params.value |> MomentRe.momentWithDate}
       />
     | RadioGroup(params) =>
       <RadioButtonGroup
         label={input_props.label}
         options={params.options}
         value={params.value}
         onChange={input_props.onChange}
         row={params.row_layout}
       />
     | Select(params) =>
       <SelectComponent
         label={input_props.label}
         value={params.value}
         onChange={input_props.onChange}
         items={params.items}
       />
     | CheckBox(params) =>
       <CheckBoxGroup
         label={input_props.label}
         selected={params.selected}
         onChange={input_props.onChange}
         options={params.options}
         row_layout={params.row_layout}
       />
     | SelectCheckBoxes(params) =>
       <SelectWithCheckBoxes
         label={input_props.label}
         selected={params.selected}
         onChange={input_props.onChange}
         items={params.options}
         renderValue={params.renderValue}
       />
     | KeyInputTime(time_params) =>
       <TimeInput
         label={input_props.label}
         format={time_params.format}
         invalidDateMessage={time_params.invalidDateMessage}
         placeholder={input_props.placeholder}
         onChange={(date: Js.Nullable.t(MomentRe.Moment.t)) =>
           switch (Js.Nullable.toOption(date)) {
           | None => ()
           | Some(date) => time_params.onChange(date |> MomentRe.Moment.toDate)
           }
         }
         value={time_params.value |> MomentRe.momentWithDate}
       />
     | Input(value) =>
       <MaterialUi.TextField
         label={React.string(input_props.label)}
         margin=`Dense
         size=`Medium
         value={MaterialUi.TextField.Value.string(value)}
         onBlur={_ => input_props.onBlur()}
         disabled={input_props.isDisabled}
         onChange={event => {
           /* Reason - https://reactjs.org/docs/events.html#event-pooling */
           ReactEvent.Form.persist(event);
           setWarning(_ => input_props.warning(event));
           input_props.onChange(event);
         }}
         placeholder={input_props.placeholder}
         variant=`Outlined
         className="form-input"
         _InputLabelProps={"className": "form-input-label"}
         _InputProps={"className": "form-input-text"}
       />
     }}
    {getWarningOrError(warning, input_props.result)}
  </div>;
};
