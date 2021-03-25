/* This component is made to fulfill the requirements of Packers & Movers.
    It will replace either DatePicker v1 or will be reverted by 15th April 2021.
   */
[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentRe.Moment.t => unit,
      ~value: option(MomentRe.Moment.t),
      ~minDate: option(MomentRe.Moment.t),
      ~maxDate: option(MomentRe.Moment.t),
      ~format: string="DD/MM/YYYY",
      ~disableFuture: option(bool),
      ~disablePast: option(bool),
      ~disabled: bool,
      ~variant: string,
      ~inputVariant: string,
      ~autoOk: bool,
      ~className: string
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUIDatePicker
      onChange
      value = {
        value
        ->Js.Null.fromOption
        ->OptionTypeUtils.OptionMomentToMomentMap.optionMomentToMoment;
      }
      minDate
      format
      maxDate
      disableFuture
      disablePast
      autoOk
      disableToolbar=true
      disabled
      variant
      label
      inputVariant
      className
    />
  </MuiPickersUtilsProvider>;
};
