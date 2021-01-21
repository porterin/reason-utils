let getWarningOrError =
    (warning: option(string), result: option(result('a, 'b))): React.element => {
  <div className="input-error-container">
    {switch (result) {
     | None =>
       switch (warning) {
       | None => React.null
       | Some(warning) => <div className="warning"> {React.string(warning)} </div>
       }
     | Some(result) =>
       switch (result) {
       | Error(err) => <div className="error"> {React.string(err)} </div>
       | _ => React.null
       }
     }}
  </div>;
};

[@react.component]
let make = (~className: string, ~children: React.element) => {
  <div className={"form-input-container " ++ className}> children </div>;
};
