module A = {
  [@react.component]
  let make = () => {
    MomentUtils.setTz("Asia/Kolkata");
    let (time, setTime) = React.useState(_ => None);
    <FormInput.KeyInputTime
      input_props={FormInput.make_props(
        ~label="",
        ~onChange=_ => (),
        ~result={Some(Ok(None))},
        ~helper_text=Text("Enter time in 24 Hour format (HH:MM)"),
        (),
      )}
      time_props={
        value: time->Belt.Option.mapWithDefault(None, v => v->Timestamp.toJsDate->Some),
        onChange: date =>
          setTime(_ => date->Belt.Option.mapWithDefault(None, v => v->Timestamp.fromJsDate->Some)),
        format: "HH:mm",
        ampm: false,
      }
    />;
  };
};

/* module B = {
  open MaterialUIPickerV4Bindings;
  [@react.component]
  let make = (~label="") => {
    MomentTz.setTz("Asia/Kolkata");
    let (date, setdate) = React.useState(_ => Some(MomentUtils.now()));
    Js.log(date);
    let handleDateChange = (d: MomentTz.Moment.t) => {
      setdate(_ => Some(d));
    };
    <LocalizationProvider dateAdapter=getMomentAdapter()>
      <TimePicker
        renderInput={props => TextField.make(~props, ~label)}
        value={date}
        onChange={date => handleDateChange(date)}
        ampm=false
      />
    </LocalizationProvider>;
  };
};
 */
ReactDOMRe.renderToElementWithId(<A />, "root");
