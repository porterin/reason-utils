[@react.component]
let make = () => {
  let (a, b) = React.useState(_ => None);
  <div>
    <Catalyst.FormInput.KeyInputTime
      input_props={Catalyst.FormInput.make_props(
        ~label="Time",
        ~onChange=_ => (),
        ~result={None},
        (),
      )}
      time_props={
        value: a,
        onChange: date =>
          {switch (date) {
           | None => Js.log("No value")
           | Some(v) => Js.log2("value", v)
           };
           b(_ => date)},
        format: "HH:mm",
        ampm: false,
      }
    />
  </div>;
};
