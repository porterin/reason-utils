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
    <DatePicker
      label={input_props.label}
      disabled={input_props.isDisabled}
      onChange={date => date_props.onChange(date |> MomentTz.toJsDate)}
      value={Belt.Option.mapWithDefault(date_props.value, None, d =>
        d->MomentTz.momentWithDate->Some
      )}
      minDate={Belt.Option.mapWithDefault(date_props.minDate, None, v =>
        Some(v |> MomentTz.momentWithDate)
      )}
      maxDate={Belt.Option.mapWithDefault(date_props.maxDate, None, v =>
        Some(v |> MomentTz.momentWithDate)
      )}
      format={date_props.format}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
