[@react.component]
let make =
    (
      ~label: string,
      ~onChange: Js.Nullable.t(MomentRe.Moment.t) => unit,
      ~placeholder: string,
      ~format: string="hh:mm:ss a",
      ~value: MomentRe.Moment.t,
      ~invalidDateMessage: option(string),
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <MUITimeInput
      label
      onChange
      value
      format
      invalidDateMessage={Belt.Option.getWithDefault(invalidDateMessage, "Invalid Time Format")}
      autoOk=true
      placeholder
      variant="inline"
      inputVariant="outlined"
      className="form-input-date-time"
      views=[|"hours", "minutes", "seconds"|]
    />
  </MuiPickersUtilsProvider>;
};
