let getDefaultErrorEntity =
    (
      ~message: string,
      ~errorType: ErrorType.t=ErrorType.UnprocessedEntity,
      ~title: string="Error",
      (),
    ) => {
  Error.DefaultError(DefaultErrorPayload.{type_: errorType, title, message});
};

let resolveError = (~error: Error.t) => {
  switch (error) {
  | DefaultError(errorPayload) => errorPayload.message
  };
};

let raiseError = (~path: string, ~message: string, ~value: string="") => {
  failwith(path ++ " : " ++ message ++ " - " ++ value);
};
