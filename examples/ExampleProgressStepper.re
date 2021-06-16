%bs.raw
{|require(`../src/components/styles/main.scss`)|};


type steps =
  | First
  | Second
  | Third
  | Fourth
  | Fifth
  | Sixth;

let progressProps: list(ProgressStepper.t(steps)) = [
  {label: Text("First"), subtitle: None, name: First},
  {label: Text("Second"), subtitle: None, name: Second},
  {label: Text("Third"), subtitle: None, name: Third},
  {label: Text("Fourth"), subtitle: None, name: Fourth},
  {label: Text("Fifth"), subtitle: None, name: Fifth},
  {label: Text("Sixth"), subtitle: None, name: Sixth},
];

[@react.component]
let make = () => {
  let {steppers, active, setActive, setCompleted, resetStepper} =
    ProgressStepperHook.useStepper(~steppers=progressProps, ~defaultActive=First, ());
  <>
    steppers
    <div className="step-buttons">
      <a
        className="step-action-btn action-btn-secondary"
        onClick={_ => {
          switch (active) {
          | First => ()
          | Second =>
            setActive(First);
            resetStepper(Second);
          | Third =>
            setActive(Second);
            resetStepper(Third);
          | Fourth =>
            setActive(Third);
            resetStepper(Fourth);
          | Fifth =>
            setActive(Fourth);
            resetStepper(Fifth);
          | Sixth =>
            setActive(Fifth);
            resetStepper(Sixth);
          }
        }}>
        {React.string("Previous")}
      </a>
      {false
         ? <a className="step-action-btn action-btn-primary" onClick={_ => ()}>
             {React.string("Submit")}
           </a>
         : <a
             className="step-action-btn action-btn-primary"
             onClick={_ => {
               switch (active) {
               | First =>
                 setCompleted(First);
                 setActive(Second);
               | Second =>
                 setCompleted(Second);
                 setActive(Third);
               | Third =>
                 setCompleted(Third);
                 setActive(Fourth);
               | Fourth =>
                 setCompleted(Fourth);
                 setActive(Fifth);
               | Fifth =>
                 setCompleted(Fifth);
                 setActive(Sixth);
               | Sixth => setCompleted(Sixth)
               }
             }}>
             {React.string("Next")}
           </a>}
    </div>
    <div className={"test-comp " ++ (active === Second ? " completed" : "")} />
  </>;
};
