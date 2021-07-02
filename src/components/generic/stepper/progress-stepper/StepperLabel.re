[@react.component]
let make =
    (
      ~label: StepperText.t,
      ~subtitle: option(StepperText.t),
      ~label_class: string,
      ~subtitle_class: string,
    ) => {
  <div className={"step-label " ++ label_class}>
    {StepperText.resolve(label)}
    {switch (subtitle) {
     | None => React.null
     | Some(sub_title) =>
       <div className={"step-label-subtitle " ++ subtitle_class}>
         {StepperText.resolve(sub_title)}
       </div>
     }}
  </div>;
};
