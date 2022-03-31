[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentTz.Moment.t => unit,
      ~value: option(MomentTz.Moment.t),
      ~minDate: option(MomentTz.Moment.t),
      ~maxDate: option(MomentTz.Moment.t),
      ~format: string="DD/MM/YYYY",
      ~disableFuture: option(bool)=?,
      ~disablePast: option(bool)=?,
      ~disabled=false,
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUIDatePicker
      onChange
      value={
        value->Js.Null.fromOption->OptionTypeUtils.OptionMomentToMomentMap.optionMomentToMoment
      }
      minDate
      format
      maxDate
      disableFuture
      disablePast
      autoOk=false
      disableToolbar=true
      disabled
      variant="inline"
      label
      inputVariant="outlined"
      className="form-input-date-time"
    />
  </MuiPickersUtilsProvider>;
};
