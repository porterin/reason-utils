[@react.component]
let make = () => {
  <div>
    <FormInput.TextInput
      input_props={FormInput.make_props(
        ~label="Comment",
        ~onChange=_event => (),
        ~placeholder="Enter comment",
        ~result={None},
        (),
      )}
      textinput_props={value: ""}
    />
  </div>;
};
