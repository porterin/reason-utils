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

let get_InputProps = (_inputProps: option(FormInputProps._inputProps)) => {
  switch (_inputProps) {
  | None => {"className": "form-input-text", "startAdornment": React.null}
  | Some(value) => {"className": value.className, "startAdornment": value.startAdornment}
  };
};
