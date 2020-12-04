module OptionMomentToMomentMap = {
  external optionMomentToMoment: Js.Null.t(MomentRe.Moment.t) => MomentRe.Moment.t = "%identity";
};

module ClearButton = {
  let closeIcon = CommonAssetsManager.getImage("close-icon-round.svg");

  [@react.component]
  let make = (~className: string="", ~cb: unit => unit): React.element => {
    <button className onClick={_ => cb()}> <img src=closeIcon /> </button>;
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
  Js.log(onClear);
  <MuiPickersUtilsProvider utils=MuiPickersUtilsProvider.utils>
    <ClearButton className="date-time-picker-cross-btn" cb={_ => onClear()} />
    <MUIDateTimePicker
      onChange
      value={Js.Null.fromOption(value) |> OptionMomentToMomentMap.optionMomentToMoment}
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
