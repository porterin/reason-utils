module type SuccessParserConfig = {
  type responseDataType;
  let execute: ResponseType.t => option(responseDataType);
};

module type ErrorParserConfig = {
  type t;
  let execute: ResponseType.t => option(t);
};

module Converter =
       (SuccessParserConfig: SuccessParserConfig, ErrorParserConfig: ErrorParserConfig) => {
  let execute =
      (response: ResponseType.t)
      : option(
          Js.Promise.t(Belt.Result.t(SuccessParserConfig.responseDataType, ErrorParserConfig.t)),
        ) => {
    response
    |> SuccessParserConfig.execute
    |> (
      data =>
        switch (data) {
        | Some(successResponse) => Some(Js.Promise.resolve(Belt.Result.Ok(successResponse)))
        | None =>
          switch (ErrorParserConfig.execute(response)) {
          | Some(error) => Some(Js.Promise.resolve(Belt.Result.Error(error)))
          | None => None
          }
        }
    );
  };
};
