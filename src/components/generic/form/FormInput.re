open Belt;
open FormInputProps;
type result('a, 'b) = Result.t('a, 'b);
let error = err => Result.Error(err);

let make_props =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~isDisabled: bool=false,
      ~placeholder="",
      ~onBlur: unit => unit=() => (),
      ~result: option(Belt.Result.t('b, 'c)),
      ~warning=_ => None,
      ~className="",
      ~_inputProps: option(_inputProps)=?,
      (),
    )
    : FormInputProps.t('b, 'c) => {
  label,
  onChange,
  isDisabled,
  placeholder,
  onBlur,
  result,
  warning,
  className,
  _inputProps,
};

module Date = {
  include FormDateInput;
};

type formInput =
  | Input(string)
  | Date(Date.date_props)
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

let get_InputProps = (_inputProps: option(_inputProps)) => {
  switch (_inputProps) {
  | None => {"className": "form-input-text", "startAdornment": React.null}
  | Some(value) => {"className": value.className, "startAdornment": value.startAdornment}
  };
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~value: formInput) => {
  let (warning, setWarning) = React.useState(_ => None);
  <div className={"form-input-container " ++ input_props.className}>
    {switch (value) {
     | Date(date_params) => <Date input_props date_props=date_params />
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
         _InputProps={get_InputProps(input_props._inputProps)}
       />
     }}
    {getWarningOrError(warning, input_props.result)}
  </div>;
};
