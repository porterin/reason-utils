[@react.component]
let make =
    (
      ~error: Error.t,
      ~refreshView: option(unit => unit)=?,
      ~className="",
      ~refreshText="Try reloading the page",
    ) => {
  <div className={"error-container " ++ className}>
    <Icon.WarningIcon fontSize=`Large />
    <div className="error-message"> {React.string(ErrorUtils.resolveError(~error))} </div>
    {switch (refreshView) {
     | None => React.null
     | Some(cb) =>
       <TertiaryButton className="text-styling-cat-items" onSelectCB=cb>
         {React.string(refreshText)}
       </TertiaryButton>
     }}
  </div>;
};
