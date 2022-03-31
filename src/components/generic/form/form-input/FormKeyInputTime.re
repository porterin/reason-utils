type t = {
  value: option(Js.Date.t),
  onChange: option(Js.Date.t) => unit,
  format: string,
  ampm: bool,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <TimeInput
      label={input_props.label}
      format={time_props.format}
      ampm={time_props.ampm}
      placeholder={input_props.placeholder}
      onChange={(date: Js.Nullable.t(MomentTz.Moment.t)) =>
        switch (Js.Nullable.toOption(date)) {
        | None => time_props.onChange(None)
        | Some(date) =>
          MomentTz.Moment.isValid(date)
            ? time_props.onChange(Some(date |> MomentTz.Moment.toDate))
            : time_props.onChange(None)
        }
      }
      value={Belt.Option.mapWithDefault(time_props.value, None, d =>
        d->MomentTz.momentWithDate->Some
      )}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
