module UnprocessedErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        type_: ErrorType.UnprocessedEntity,
        title: json |> field("type", string),
        message: json |> field("message", string),
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
        message: json |> field("error", string),
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

module DataConflicErrorHandler = {
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

module UnauthorizedErrorHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({
      type_: ErrorType.Unauthorized,
      title: "Unauthorized error",
      message: "Resource unauthorized",
    });
  };
};
