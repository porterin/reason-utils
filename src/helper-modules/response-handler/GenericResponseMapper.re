module UnprocessedErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        type_: ErrorType.UnprocessedEntity,
        title: json |> field("type", string),
        message:
          Belt.Option.getWithDefault(
            json |> optional(field("message", string)),
            "Provided values cannot be processed",
          ),
      },
    );
  };
};

module NotAcceptableErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        type_: ErrorType.NotAcceptableEntity,
        title: "Not Acceptable",
        message:
          Belt.Option.getWithDefault(
            json |> optional(field("error", string)),
            "Provided values are not acceptable",
          ),
      },
    );
  };
};

module ForbiddenErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        type_: ErrorType.Forbidden,
        title: json |> field("title", string),
        message: json |> field("message", string),
      },
    );
  };
};

module DataConflictErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        type_: ErrorType.DataConflict,
        title: json |> field("title", string),
        message: json |> field("message", string),
      },
    );
  };
};

module TimedoutErrorHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({
      type_: ErrorType.TimedoutError,
      title: "Timeout error",
      message: "Request timed out",
    });
  };
};
