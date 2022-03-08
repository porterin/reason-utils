type t = {
  value: option(Js.Date.t),
  minDate: option(Js.Date.t),
  maxDate: option(Js.Date.t),
  onChange: Js.Date.t => unit,
  format: string,
  onClear: unit => unit,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~date_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <DateTimePicker
      label={input_props.label}
      onChange={date => date_props.onChange(date |> MomentTz.Moment.toDate)}
      value={Belt.Option.mapWithDefault(date_props.value, None, date =>
        Some(date |> MomentTz.momentWithDate)
      )}
      minDate={Belt.Option.mapWithDefault(date_props.minDate, None, v =>
        Some(v |> MomentTz.momentWithDate)
      )}
      maxDate={Belt.Option.mapWithDefault(date_props.maxDate, None, v =>
        Some(v |> MomentTz.momentWithDate)
      )}
      onClear={date_props.onClear}
      format={date_props.format}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
