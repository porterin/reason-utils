[@react.component]
let make = (~steps: int, ~activeStep: int, ~className: string="") => {
  <MaterialUi.MobileStepper
    steps={MaterialUi.Number.int(steps)}
    activeStep={MaterialUi.Number.int(activeStep)}
    className
  />;
};
