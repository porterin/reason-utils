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
    let (date, setdate) = React.useState(_ => Some(MomentUtils.now()));

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
          setdate(_ =>
            date->Belt.Option.mapWithDefault(None, v => v->MomentTz.momentWithTimestampMS->Some)
          ),
        format: "HH:mm",
        ampm: false,
      }
    />;
  };
};

ReactDOMRe.renderToElementWithId(<B />, "root");
