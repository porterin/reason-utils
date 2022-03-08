[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentTz.Moment.t => unit,
      ~value: option(MomentTz.Moment.t),
      ~disabled=false,
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUITimePicker
      label
      onChange
      value={
        value->Js.Null.fromOption->OptionTypeUtils.OptionMomentToMomentMap.optionMomentToMoment
      }
      disabled
      variant="inline"
      inputVariant="outlined"
      className="form-input-date-time"
    />
  </MuiPickersUtilsProvider>;
};
