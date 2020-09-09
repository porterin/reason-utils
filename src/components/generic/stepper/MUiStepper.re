[@react.component]
let make = (~steps: int, ~activeIndex: int, ~className: string="") => {
  <MaterialUi.MobileStepper
    steps={MaterialUi.Number.int(steps)}
    activeStep={MaterialUi.Number.int(activeIndex)}
    className
  />;
};
