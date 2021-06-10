let complete_tick = AssetsManager.getImage("white-tick.svg");

type t('a) = {
  label: ViewText.t,
  subtitle: option(ViewText.t),
  name: 'a,
};

module Classes = {
  type t = {
    root: string,
    step_icon: string,
    step_label: string,
    step_subtitle: string,
    step_index: string,
    progress_step: string,
    progress_bar: string,
  };
  let make =
      (
        ~root: string="",
        ~step_icon: string="",
        ~step_label: string="",
        ~step_index: string="",
        ~progress_step: string="",
        ~progress_bar: string="",
        ~step_subtitle: string="",
        (),
      )
      : t => {
    root,
    step_icon,
    step_label,
    step_index,
    progress_step,
    progress_bar,
    step_subtitle,
  };
};

[@react.component]
let make = (~steps: list(t('a)), ~isCompleted: 'a => bool, ~activeStep: 'a, ~classes: Classes.t) => {
  <div className={"progress-bar-wrapper " ++ classes.root}>
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
              <div>
                {isCompleted(step.name)
                   ? <span className="step-icon"> <img src=complete_tick /> </span> : React.null}
                {!isCompleted(step.name)
                   ? <span className="step-index"> {React.int(index + 1)} </span> : React.null}
              </div>
              {List.length(steps) === index + 1
                 ? React.null
                 : <div
                     className={
                       "progress-bar "
                       ++ classes.progress_bar
                       ++ (
                         isCompleted(step.name) && step.name !== activeStep
                           ? " progress-bar-completed" : ""
                       )
                     }
                   />}
              <div className={"step-label " ++ classes.step_label}>
                {ViewText.resolve(step.label)}
                {switch (step.subtitle) {
                 | None => React.null
                 | Some(sub_title) =>
                   <div className={"step-label-subtitle " ++ classes.step_subtitle}>
                     {ViewText.resolve(sub_title)}
                   </div>
                 }}
              </div>
            </li>
          })
       |> ReasonReactUtils.listToReactArray}
    </ul>
  </div>;
};
