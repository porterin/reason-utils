type t = {
  value: option(Js.Date.t),
  onChange: Js.Date.t => unit,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <TimePicker
      label={input_props.label}
      disabled={input_props.isDisabled}
      onChange={date => time_props.onChange(date |> MomentTz.Moment.toDate)}
      value={Belt.Option.mapWithDefault(time_props.value, None, d =>
        d->MomentTz.momentWithDate->Some
      )}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
