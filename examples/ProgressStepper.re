%bs.raw
{|require(`./_progress.scss`)|};

type subStep('b) = {
  label: string,
  subtitle: option(string),
  name: 'b,
}

type progressStep('t,'b) = {
  label: string,
  subtitle: option(string),
  name: 't,
  subSteps: option(list(subStep('b)))
};

[@react.component]
let make = (~steps: list(progressStep('t, 'b)), ~isCompleted: 't => bool, ~activeStep: 't) => {
  <div className="progress-bar-wrapper">
    <ul className="step-progress-bar">
      {steps
       |> List.mapi((index, step) => {
            <li
              key={index->string_of_int}
              className={
                "progress-step "
                ++ (isCompleted(step.name) ? "completed " : "")
                ++ (step.name === activeStep ? " current" : "")
              }>
              {isCompleted(step.name)
                 ? <span className="step-icon">
                     <svg
                       width="1.5rem"
                       viewBox="0 0 13 9"
                       fill="none"
                       xmlns="http://www.w3.org/2000/svg">
                       <path d="M1 3.5L4.5 7.5L12 1" stroke="white" strokeWidth="1.5" />
                     </svg>
                   </span>
                 : React.null}
              {!isCompleted(step.name)
                 ? <span className="step-index"> {React.int(index + 1)} </span> : React.null}
              <div className="step-label">
                {React.string(step.label)}
                {switch (step.subtitle) {
                 | None => React.null
                 | Some(sub_title) =>
                   <div className="step-label-subtitle"> {React.string(sub_title)} </div>
                 }}
              </div>
            </li>
          })
       |> ReasonReactUtils.listToReactArray}
    </ul>
  </div>;
};
