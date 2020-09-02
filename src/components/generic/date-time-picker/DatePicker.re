[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentRe.Moment.t => unit,
      ~value: MomentRe.Moment.t,
      ~minDate: option(MomentRe.Moment.t),
      ~maxDate: option(MomentRe.Moment.t),
      ~format: string="DD/MM/YYYY",
      ~disableFuture: option(bool)=?,
      ~disablePast: option(bool)=?,
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUIDatePicker
      onChange
      value
      minDate
      format
      maxDate
      disableFuture
      disablePast
      autoOk=true
      disableToolbar=true
      variant="inline"
      label
      inputVariant="outlined"
      className="form-input-date-time"
    />
  </MuiPickersUtilsProvider>;
};
