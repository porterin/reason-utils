type t('a) = {
  label: StepperText.t,
  subtitle: option(StepperText.t),
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
  <div className={"progress-stepper-root" ++ classes.root}>
    <ul className="progress-stepper">
      {steps
       |> List.mapi((index, step) => {
            <li
              key={index->string_of_int}
              className={
                "progress-step "
                ++ (isCompleted(step.name) ? "completed " : "")
                ++ (step.name === activeStep ? " current" : "")
              }>
              <StepIcon is_completed={isCompleted(step.name)} index />
              <StepProgressbar
                progress_bar_class={classes.progress_bar}
                is_completed={isCompleted(step.name)}
                is_in_active={step.name !== activeStep}
              />
              <StepperLabel
                label={step.label}
                subtitle={step.subtitle}
                label_class={classes.step_label}
                subtitle_class={classes.step_subtitle}
              />
            </li>
          })
       |> ReasonReactUtils.listToReactArray}
    </ul>
  </div>;
};
