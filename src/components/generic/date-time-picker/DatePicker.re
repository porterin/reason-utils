[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentRe.Moment.t => unit,
      ~value: option(MomentRe.Moment.t),
      ~minDate: option(MomentRe.Moment.t),
      ~maxDate: option(MomentRe.Moment.t),
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
