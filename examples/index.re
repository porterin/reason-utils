module TestComponents = {
  [@react.component]
  let make = () => {
    <div>
    /* Previous Implementation */
      /* <FormInput
        input_props={FormInput.make_props(
          ~label="Date",
          ~onChange=_ => (),
          
          ~result={form.dateResult},
          (),
        )}
        value=
            {Date({
               value: form.input.date,
               minDate: None,
               maxDate: None,
               onChange: date =>
                 form.updateDate((input, value) => {...input, date: value}, date),
               format: "dd/MM/YYYY",
             })},
      /> */
      <FormInput
        input_props={FormInput.make_props(~label="Date", ~onChange=_ => (), ~result={None}, ())}
        value={
          Date({
            value: DateTime.now(),
            minDate: None,
            maxDate: None,
            onChange: _date => (),
            format: "dd/MM/YYYY",
          })
        }
      />
    </div>;
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
