/* module A = {
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
    */

module B = {
  [@react.component]
  let make = () => {
    MomentTz.setTz("Asia/Kolkata");
    Js.log(MomentTz.getTz());
    let (date, setdate) = React.useState(_ => None);

    <FormKeyInputTime
      input_props={FormInput.make_props(
        ~label="",
        ~onChange=_ => (),
        ~result={Some(Ok(None))},
        ~helper_text=Text("Enter time in 24 Hour format (HH:MM)"),
        (),
      )}
      time_props={
        value: date->Belt.Option.mapWithDefault(None, v => v->MomentTz.valueOf->Some),
        onChange: date =>
          setdate(_ => {
            Js.log(date);
            date->Belt.Option.mapWithDefault(None, v => v->MomentTz.momentWithTimestampMS->Some);
          }),
        format: "HH:mm",
        ampm: false,
      }
    />;
  };
};

module C = {
  [@react.component]
  let make = () => {
    let (date, setDate) = React.useState(_ => None);
    Belt.Option.forEach(date, d => Js.log(MomentTz.valueOf(d)));
    <DatePickerTzBinding
      tz="Asia/Kolkata"
      date
      handleDateChange={date => setDate(_ => date->Some)}
    />;
  };
};

ReactDOMRe.renderToElementWithId(<C />, "root");
