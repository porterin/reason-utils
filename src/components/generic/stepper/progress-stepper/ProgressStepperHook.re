type stepperHookRt('a) = {
  steppers_cmp: React.element,
  active: 'a,
  setActive: 'a => unit,
  setCompleted: 'a => unit,
  resetStepper: 'a => unit,
};

let useStepper =
    (
      ~steppers: list(ProgressStepper.t('a)),
      ~defaultActive: 'a,
      ~classes: Catalyst.ProgressStepper.Classes.t=ProgressStepper.Classes.make(),
      (),
    ) => {
  let (active, setActive) = React.useState(_ => defaultActive);
  let (completed, setCompleted) = React.useState(_ => []);

  let steppers_cmp =
    <ProgressStepper
      steps=steppers
      activeStep=active
      isCompleted={stepper_id => List.exists(s => s == stepper_id, completed)}
      classes
    />;
  {
    steppers_cmp,
    active,
    setActive: a => setActive(_ => a),
    setCompleted: a => setCompleted(pre => [a, ...pre]),
    resetStepper: a => setCompleted(pre => List.filter(b => b !== a, pre)),
  };
};
