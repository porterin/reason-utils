[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentRe.Moment.t => unit,
      ~value: option(MomentRe.Moment.t),
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
