type t('a) = {
  stepper_id: 'a,
  stepper_number: int,
  label: CommonTypes.viewText,
};

type stepperHookRt('a) = {
  steppers: React.element,
  active: 'a,
  setActive: 'a => unit,
  setCompleted: 'a => unit,
  resetStepper: 'a => unit,
};

let useStepper = (~steppers: list(t('a)), ~defaultActive: 'a) => {
  let (active, setActive) = React.useState(_ => defaultActive);
  let (completed, setCompleted) = React.useState(_ => []);
  let steppers =
    <MaterialUi.Stepper
      alternativeLabel=true
      nonLinear=true
      activeStep={MaterialUi_Types.Number.int(
        List.find(a => a.stepper_id == active, steppers).stepper_number,
      )}>
      {steppers
       |> List.mapi((index: int, step: t('a)) => {
            <MaterialUi.Step key={string_of_int(index)}>
              <MaterialUi.StepButton
                completed={List.exists(s => s == step.stepper_id, completed)}>
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
  {
    steppers,
    active,
    setActive: a => setActive(_ => a),
    setCompleted: a => setCompleted(pre => [a, ...pre]),
    resetStepper: a => setCompleted(pre => List.filter(b => b !== a, pre)),
  };
};
