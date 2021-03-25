let error_exclamation = AssetsManager.getImage("error-exclamation.svg");

let getHelperText = (helper_text: CommonTypes.viewText) => {
  switch (helper_text) {
  | NoText => React.null
  | Text(msg) => <div className="helper-text"> {React.string(msg)} </div>
  | Custom(fn) => fn()
  };
};

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
       | None => getHelperText(helper_text)
       | Some(warning) => <div className="warning"> {React.string(warning)} </div>
       }
     | Some(result) =>
       switch (result) {
       | Error(err) => <div className="error"> <img src=error_exclamation /> {React.string(err)} </div>
       | _ => getHelperText(helper_text)
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
