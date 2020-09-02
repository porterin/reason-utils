[@react.component]
let make =
    (~label: string, ~onChange: MomentRe.Moment.t => unit, ~value: MomentRe.Moment.t)
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUITimePicker
      label
      onChange
      value
      autoOk=true
      variant="inline"
      inputVariant="outlined"
      className="form-input-date-time"
    />
  </MuiPickersUtilsProvider>;
};
