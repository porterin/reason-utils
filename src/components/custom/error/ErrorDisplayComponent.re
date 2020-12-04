
[@react.component]
let make = (~error: Error.t) => {
  <div className="error-message">
      (React.string(ErrorUtils.resolveError(~error=error)))
  </div>
}
