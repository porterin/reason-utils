[@react.component]
let make = (~steps: int, ~activeIndex: int) => {
  <MaterialUi.MobileStepper
    steps={MaterialUi.Number.int(steps)}
    activeStep={MaterialUi.Number.int(activeIndex)}
  />;
};
