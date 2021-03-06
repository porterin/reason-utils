/* To Be Deprecated Soon */
/* No Transition */
type t('a) = {
  stepper_id: 'a,
  stepper_number: int,
  label: CommonTypes.viewText,
};

module Classes = {
  type t = {
    root: string,
    horizontal: string,
    vertical: string,
    alternativeLabel: string,
  };
  let make =
      (
        ~root: string="",
        ~horizontal: string="",
        ~vertical: string="",
        ~alternativeLabel: string="",
        (),
      )
      : t => {
    root,
    horizontal,
    vertical,
    alternativeLabel,
  };
};

[@react.component]
let make =
    (
      ~steppers: list(t('a)),
      ~activeStep: int,
      ~isCompleted: 'a => bool,
      ~classes: option(Classes.t)=?,
    ) => {
  <MaterialUi.Stepper
    classes={
      switch (classes) {
      | Some(classes) =>
        MaterialUi_Stepper.Classes.make(
          ~root=classes.root,
          ~horizontal=classes.horizontal,
          ~vertical=classes.vertical,
          ~alternativeLabel=classes.alternativeLabel,
          (),
        )
      | None => MaterialUi_Stepper.Classes.make()
      }
    }
    alternativeLabel=true
    nonLinear=true
    activeStep={MaterialUi_Types.Number.int(activeStep)}>
    {steppers
     |> List.mapi((index: int, step: t('a)) => {
          <MaterialUi.Step
            key={string_of_int(index)}
            classes={MaterialUi.Step.Classes.make(
              ~root="step-root",
              ~horizontal="step-horizontal",
              ~vertical="step-vertical",
              ~alternativeLabel="step-alternative-label",
              ~completed="step-completed",
              (),
            )}>
            <MaterialUi.StepButton
              classes={MaterialUi.StepButton.Classes.make(
                ~root="step-button-root",
                ~horizontal="step-button-horizontal",
                ~vertical="step-button-vertical",
                ~touchRipple="step-button-touch-ripple",
                (),
              )}
              completed={isCompleted(step.stepper_id)}>
              {switch (step.label) {
               | Text(label) => <div> {React.string(label)} </div>
               | Custom(fn) => fn()
               | NoText => React.null
               }}
            </MaterialUi.StepButton>
          </MaterialUi.Step>
        })
     |> ReasonReactUtils.listToReactArray}
  </MaterialUi.Stepper>;
};
