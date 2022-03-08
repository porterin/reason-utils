/* This component is made to fulfill the requirements of Packers & Movers.
    It will replace either DatePicker v1 or will be reverted by 15th April 2021.
   */

type t = {
  value: option(Js.Date.t),
  minDate: option(Js.Date.t),
  maxDate: option(Js.Date.t),
  onChange: Js.Date.t => unit,
  format: string,
  variant: string,
  inputVariant: string,
  disableFuture: option(bool),
  disablePast: option(bool),
  autoOk: bool,
  className: string
};

let make_props =
    (
      ~value: option(Js.Date.t)=None,
      ~minDate: option(Js.Date.t)=None,
      ~maxDate: option(Js.Date.t)=None,
      ~onChange: Js.Date.t => unit,
      ~variant: string="inline",
      ~inputVariant="outlined",
      ~disableFuture: option(bool)=None,
      ~disablePast: option(bool)=None,
      ~autoOk: bool=true,
      ~className: string="form-input-date-time",
      ~format: string,
      ()
    )
    : t => {
  value,
  minDate,
  maxDate,
  onChange,
  format,
  variant,
  inputVariant,
  disableFuture,
  disablePast,
  autoOk,
  className
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~date_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <DatePickerV2
      label={input_props.label}
      disabled={input_props.isDisabled}
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
      format={date_props.format}
      variant=date_props.variant
      inputVariant=date_props.inputVariant
      disablePast=date_props.disablePast
      disableFuture=date_props.disableFuture
      autoOk=date_props.autoOk
      className=date_props.className
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
