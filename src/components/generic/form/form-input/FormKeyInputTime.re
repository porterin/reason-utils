type t = {
  value: option(Js.Date.t),
  onChange: option(Js.Date.t) => unit,
  format: string,
  ampm: bool,
};

module B = {
  open MaterialUIPickerV4Bindings;
  [@react.component]
  let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
    <LocalizationProvider dateAdapter={getMomentAdapter()}>
      <TimePicker
        renderInput={props =>
          TextField.make(
            ~props,
            ~placeholder={
              input_props.placeholder;
            },
            ~label={
              input_props.label;
            },
          )
        }
        value={Belt.Option.mapWithDefault(time_props.value, None, d =>
          d->MomentTz.momentWithDate->Some
        )}
        onChange={(date: Js.Nullable.t(MomentTz.Moment.t)) =>
          switch (Js.Nullable.toOption(date)) {
          | None => time_props.onChange(None)
          | Some(date) =>
            MomentTz.isValid(date)
              ? time_props.onChange(Some(date |> MomentTz.toJsDate |> MomentUtils.setOtherZone))
              : time_props.onChange(None)
          }
        }
        ampm={time_props.ampm}
        inputFormat={time_props.format}
      />
    </LocalizationProvider>;
  };
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~time_props: t) => {
  MomentUtils.setTz("Asia/Kolkata");
  <FormInputWrapper className={input_props.className}>
   /*  <TimeInput
      label={input_props.label}
      format={time_props.format}
      ampm={time_props.ampm}
      placeholder={input_props.placeholder}
      onChange={(date: Js.Nullable.t(MomentTz.Moment.t)) =>
        switch (Js.Nullable.toOption(date)) {
        | None => time_props.onChange(None)
        | Some(date) =>
          MomentTz.isValid(date)
            ? time_props.onChange(Some(date |> MomentTz.toJsDate |> MomentUtils.setOtherZone))
            : time_props.onChange(None)
        }
      }
      value={Belt.Option.mapWithDefault(time_props.value, None, d =>
        d->MomentTz.momentWithDate->Some
      )}
    /> */
    <B input_props time_props/>
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
