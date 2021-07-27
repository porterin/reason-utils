[@react.component]
let make =
    (
      ~label: string,
      ~onChange: Js.Nullable.t(MomentRe.Moment.t) => unit,
      ~placeholder: string,
      ~format: string="hh:mm:ss a",
      ~value: option(MomentRe.Moment.t),
      ~ampm: bool,
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUITimeInput
      label
      onChange
      value={
        value->Js.Null.fromOption->OptionTypeUtils.OptionMomentToMomentMap.optionMomentToMoment
      }
      ampm
      invalidDateMessage=React.null
      format
      autoOk=true
      placeholder
      variant="inline"
      inputVariant="outlined"
      className="form-input-date-time"
      views=[|"hours", "minutes", "seconds"|]
    />
  </MuiPickersUtilsProvider>;
};
