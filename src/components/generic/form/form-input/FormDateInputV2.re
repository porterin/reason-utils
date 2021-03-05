type t = {
  value: option(Js.Date.t),
  minDate: option(Js.Date.t),
  maxDate: option(Js.Date.t),
  onChange: Js.Date.t => unit,
  format: string,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~date_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <DatePickerV2
      label={input_props.label}
      disabled={input_props.isDisabled}
      onChange={date => date_props.onChange(date |> MomentRe.Moment.toDate)}
      value={Belt.Option.mapWithDefault(date_props.value, None, date =>
        Some(date |> MomentRe.momentWithDate)
      )}
      minDate={Belt.Option.mapWithDefault(date_props.minDate, None, v =>
        Some(v |> MomentRe.momentWithDate)
      )}
      maxDate={Belt.Option.mapWithDefault(date_props.maxDate, None, v =>
        Some(v |> MomentRe.momentWithDate)
      )}
      format={date_props.format}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
