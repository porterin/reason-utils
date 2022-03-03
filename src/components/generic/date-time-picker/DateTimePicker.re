module ClearButton = {
  let closeIcon = AssetsManager.getImage("close-icon-round.svg");

  [@react.component]
  let make = (~className: string="", ~cb: unit => unit): React.element => {
    <span className={className ++ " close-btn"} onClick={(_event: ReactEvent.Mouse.t) => cb()}>
      <Icon.CloseIcon fontSize=`Small />
    </span>;
  };
};

[@react.component]
let make =
    (
      ~label: string,
      ~onChange: MomentRe.Moment.t => unit,
      ~value: option(MomentRe.Moment.t),
      ~minDate: option(MomentRe.Moment.t),
      ~maxDate: option(MomentRe.Moment.t),
      ~format: string="DD/MM/YYYY hh:mm A",
      ~disableFuture: option(bool)=?,
      ~disablePast: option(bool)=?,
      ~onClear: unit => unit,
    )
    : React.element => {
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <ClearButton className="date-time-clear" cb={_ => onClear()} />
    <MUIDateTimePicker
      onChange
      value={
        value->Js.Null.fromOption->OptionTypeUtils.OptionMomentToMomentMap.optionMomentToMoment
      }
      minDate
      format
      maxDate
      disableFuture
      disablePast
      autoOk=true
      disableToolbar=false
      variant="inline"
      label
      inputVariant="outlined"
      className="form-input-date-time"
    />
  </MuiPickersUtilsProvider>;
};
