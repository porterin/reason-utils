%bs.raw
{|require(`./_progress.scss`)|};

type stepStates =
  | NOT_STARTED
  | CURRENT
  | ERROR
  | COMPLETED;

type progressStep('t) = {
  label: string,
  subtitle: option(string),
  name: 't,
  state: stepStates,
};

type stepProgressProps('t) = {
  steps: list(progressStep('t)),
  startingStep: 't,
};

[@react.component]
let make = (~props: stepProgressProps('t)) => {
  <div className="progress-bar-wrapper">
    <ul className="step-progress-bar">
      {props.steps
       |> List.mapi((index, step) => {
            <li
              key={index->string_of_int}
              className={
                "progress-step "
                ++ (step.state === COMPLETED ? "completed" : "")
                ++ (step.state === CURRENT ? "current" : "")
                ++ (step.state === ERROR ? "has-error" : "")
              }>
              {step.state === COMPLETED
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
              {step.state === ERROR
                 ? <span className="step-icon"> {React.string("!")} </span> : React.null}
              {step.state !== COMPLETED && step.state !== ERROR
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
