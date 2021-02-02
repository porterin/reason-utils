module TestComponents = {
  [@react.component]
  let make = () => {
    <div>

        <FormInput.Date
          input_props={Catalyst.FormInput.make_props(
            ~label="Date",
            ~onChange=_ => (),
            ~result={None},
            (),
          )}
          date_props={
            value: Js.Date.fromFloat(Js.Date.now()),
            minDate: None,
            maxDate: None,
            onChange: _date => (),
            format: "dd/MM/YYYY",
          }
        />
      </div>;
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
