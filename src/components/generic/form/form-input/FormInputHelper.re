let getWarningOrError =
    (
      warning: option(string),
      result: option(result('a, 'b)),
      helper_text: CommonTypes.viewText,
    )
    : React.element => {
  <div className="input-error-container">
    {switch (result) {
     | None =>
       switch (warning) {
       | None =>
         switch (helper_text) {
         | NoText => React.null
         | Text(msg) => <div className="helper-text"> {React.string(msg)} </div>
         | Custom(fn) => fn()
         }
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
