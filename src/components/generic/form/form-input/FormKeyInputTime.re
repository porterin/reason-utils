type t = {
  value: Js.Date.t,
  onChange: Js.Date.t => unit,
  format: string,
  invalidDateMessage: option(string),
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <TimeInput
      label={input_props.label}
      format={time_props.format}
      invalidDateMessage={time_props.invalidDateMessage}
      placeholder={input_props.placeholder}
      onChange={(date: Js.Nullable.t(MomentRe.Moment.t)) =>
        switch (Js.Nullable.toOption(date)) {
        | None => ()
        | Some(date) => time_props.onChange(date |> MomentRe.Moment.toDate)
        }
      }
      value={time_props.value |> MomentRe.momentWithDate}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
