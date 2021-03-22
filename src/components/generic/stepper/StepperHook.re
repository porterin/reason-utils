type stepperHookRt('a) = {
  steppers: React.element,
  active: 'a,
  setActive: 'a => unit,
  setCompleted: 'a => unit,
  resetStepper: 'a => unit,
};

let useStepper =
    (
      ~classes: Catalyst.Stepper.Classes.t=Stepper.Classes.make(),
      ~steppers: list(Stepper.t('a)),
      ~defaultActive: 'a,
    ) => {
  let (active, setActive) = React.useState(_ => defaultActive);
  let (completed, setCompleted) = React.useState(_ => []);

  let activeStep =
    List.find((a: Stepper.t('a)) => a.stepper_id == active, steppers).stepper_number;
  let steppers =
    <Stepper
      classes
      steppers
      activeStep
      isCompleted={stepper_id => List.exists(s => s == stepper_id, completed)}
    />;
  {
    steppers,
    active,
    setActive: a => setActive(_ => a),
    setCompleted: a => setCompleted(pre => [a, ...pre]),
    resetStepper: a => setCompleted(pre => List.filter(b => b !== a, pre)),
  };
};
