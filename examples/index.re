module TestComponents = {
  type steps =
    | First
    | Second
    | Third;

  type subSteps =
    | SecondPoint1
    | SecondPoint2;

  let subSteps: list(ProgressStepper.subStep(subSteps)) = [
    {label: "First", subtitle: None, name: SecondPoint1},
    {label: "First", subtitle: None, name: SecondPoint1},
    {label: "First", subtitle: None, name: SecondPoint1},
  ];

  let progressProps: list(ProgressStepper.progressStep(steps, subSteps)) = [
    {label: "First", subtitle: None, name: First, subSteps: None},
    {label: "Second", subtitle: None, name: Second, subSteps: Some(subSteps)},
    {label: "Third", subtitle: None, name: Third, subSteps: None},
  ];

  [@react.component]
  let make = () => {
    let {steppers, active, setActive, setCompleted, resetStepper} =
      StepHook.useStepper(~steppers=progressProps, ~defaultActive=First);
    <>
      <ExampleTransition />
      steppers
      <div className="step-buttons">
        <a
          className="step-action-btn action-btn-secondary"
          onClick={_ => {
            switch (active) {
            | First => ()
            | Second =>
              setActive(First);
              resetStepper(Second);
            | Third =>
              setActive(Second);
              resetStepper(Third);
            }
          }}>
          {React.string("Previous")}
        </a>
        {false
           ? <a className="step-action-btn action-btn-primary" onClick={_ => ()}>
               {React.string("Submit")}
             </a>
           : <a
               className="step-action-btn action-btn-primary"
               onClick={_ => {
                 switch (active) {
                 | First =>
                   setCompleted(First);
                   setActive(Second);
                 | Second =>
                   setCompleted(Second);
                   setActive(Third);
                 | Third => setCompleted(Third)
                 }
               }}>
               {React.string("Next")}
             </a>}
      </div>
      <div className={"test-comp " ++ (active===Second ? " completed" : "")}/>
    </>;
  };
};

ReactDOMRe.renderToElementWithId(<ExampleFormInput />, "root");
