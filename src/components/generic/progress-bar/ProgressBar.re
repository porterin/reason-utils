module ProgressBarWithLabel = {
  let progressWithLabel =
      (
        progress,
        top_right_content,
        bottom_left_content,
        top_left_content,
        bottom_right_content,
        progress_bar_class_name,
      ) => {
    <MaterialUi.Box className="progress-container">
      <Row className="top-text-container">
        <MaterialUi.Typography variant=`H6 color=`TextSecondary className="top-left-text">
          {switch (top_left_content) {
           | Some(data) => data
           | None => React.null
           }}
        </MaterialUi.Typography>
        <MaterialUi.Typography variant=`H6 color=`TextSecondary className="top-right-text">
          {switch (top_right_content) {
           | Some(data) => data
           | None => React.null
           }}
        </MaterialUi.Typography>
      </Row>
      <MaterialUi.Box className="progress-box">
        <MaterialUi.LinearProgress
          className={"progress-bar " ++ progress_bar_class_name}
          color=`Secondary
          variant=`Determinate
          value=progress
        />
      </MaterialUi.Box>
      <Row className="bottom-text-container">
        <MaterialUi.Typography variant=`H6 color=`TextSecondary className="bottom-left-text">
          {switch (bottom_left_content) {
           | Some(data) => data
           | None => React.null
           }}
        </MaterialUi.Typography>
        <MaterialUi.Typography variant=`H6 color=`TextSecondary className="bottom-right-text">
          {switch (bottom_right_content) {
           | Some(data) => data
           | None => React.null
           }}
        </MaterialUi.Typography>
      </Row>
    </MaterialUi.Box>;
  };
};

[@react.component]
let make =
    (
      ~value: float=0.0,
      ~class_name: string="",
      ~bottom_left_content: option(React.element)=?,
      ~top_left_content: option(React.element)=?,
      ~bottom_right_content: option(React.element)=?,
      ~top_right_content: option(React.element)=?,
      ~progress_bar_class_name: string="",
    ) => {
  <div className=class_name>
    {ProgressBarWithLabel.progressWithLabel(
       MaterialUi_Types.Number.float(value),
       top_right_content,
       bottom_left_content,
       top_left_content,
       bottom_right_content,
       progress_bar_class_name,
     )}
  </div>;
};
