let getDefaultErrorEntity =
    (
      ~message: string,
      ~title=ErrorType.Default,
      (),
    ) => {
  Error.DefaultError(DefaultErrorPayload.{title, message});
};

let resolveError = (~error: Error.t) => {
  switch (error) {
  | DefaultError(errorPayload) => errorPayload.message
  };
};

let raiseError = (~path: string, ~message: string, ~value: string="") => {
  failwith(path ++ " : " ++ message ++ " - " ++ value);
};
