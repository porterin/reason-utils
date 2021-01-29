type t = {
  value: Js.Date.t,
  onChange: Js.Date.t => unit,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <TimePicker
      label={input_props.label}
      disabled={input_props.isDisabled}
      onChange={date => time_props.onChange(date |> MomentRe.Moment.toDate)}
      value={time_props.value |> MomentRe.momentWithDate}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
