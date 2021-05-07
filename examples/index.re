module TestComponents = {
  type steps =
    | First
    | Second
    | Third;
  let progressProps: ProgressStepper.stepProgressProps(steps) = {
    steps: [
      {label: "First", subtitle: None, name: First, state: CURRENT},
      {label: "Second", subtitle: None, name: Second, state: NOT_STARTED},
      {label: "Third", subtitle: None, name: Third, state: NOT_STARTED},
    ],
    startingStep: First,
  };

  [@react.component]
  let make = () => {
    let (state, useState) = React.useState(_ => progressProps);
    <>
      <ExampleTransition />
      <ProgressStepper props=state />
      <div className="step-buttons">
        <a
          className="step-action-btn action-btn-secondary"
          onClick={_ =>
            useState(prev =>
              {
                ...prev,
                steps: [
                  {label: "First", subtitle: None, name: First, state: COMPLETED},
                  {label: "Second", subtitle: None, name: Second, state: CURRENT},
                  {label: "Third", subtitle: None, name: Third, state: NOT_STARTED},
                ],
              }
            )
          }>
          {React.string("Previous")}
        </a>
        {false
           ? <a className="step-action-btn action-btn-primary" onClick={_ => ()}>
               {React.string("Submit")}
             </a>
           : <a
               className="step-action-btn action-btn-primary"
               onClick={_ =>
                 useState(prev =>
                   {
                     ...prev,
                     steps: [
                       {label: "First", subtitle: None, name: First, state: COMPLETED},
                       {label: "Second", subtitle: None, name: Second, state: CURRENT},
                       {label: "Third", subtitle: None, name: Third, state: NOT_STARTED},
                     ],
                   }
                 )
               }>
               {React.string("Next")}
             </a>}
      </div>
    </>;
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
