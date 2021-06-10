type stepperHookRt('a) = {
  steppers: React.element,
  active: 'a,
  setActive: 'a => unit,
  setCompleted: 'a => unit,
  resetStepper: 'a => unit,
};

let useStepper = (~steppers: list(ProgressStepper.t('a)), ~defaultActive: 'a) => {
  let (active, setActive) = React.useState(_ => defaultActive);
  let (completed, setCompleted) = React.useState(_ => []);

  let activeStep = List.find((a: ProgressStepper.t('a)) => a.name == active, steppers).name;
  let steppers =
    <ProgressStepper
      steps=steppers
      activeStep
      isCompleted={stepper_id => List.exists(s => s == stepper_id, completed)}
      classes={ProgressStepper.Classes.make()}
    />;
  {
    steppers,
    active,
    setActive: a => setActive(_ => a),
    setCompleted: a => setCompleted(pre => [a, ...pre]),
    resetStepper: a => setCompleted(pre => List.filter(b => b !== a, pre)),
  };
};
