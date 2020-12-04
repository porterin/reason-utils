[@react.component]
let make = (~error: Error.t, ~refreshView: option(unit => unit)=?, ~className="") => {
  <div className={"error-container " ++ className}>
    <Icon.WarningIcon fontSize=`Large />
    <div className="error-message"> {React.string(ErrorUtils.resolveError(~error))} </div>
    {switch (refreshView) {
     | None => React.null
     | Some(cb) =>
       <TertiaryButton className="text-styling-cat-items" onSelectCB=cb>
         {React.string("Try reloading the page")}
       </TertiaryButton>
     }}
  </div>;
};
