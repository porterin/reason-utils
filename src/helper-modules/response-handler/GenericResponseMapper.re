module UnprocessedErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{
        title: UnprocessedEntity(None),
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
        title: NotAcceptableEntity,
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
      Json.Decode.{title: Forbidden, message: json |> field("message", string)},
    );
  };
};

module DataConflictErrorHandler = {
  let execute = (~json: Js.Json.t): Error.t => {
    Error.DefaultError(
      Json.Decode.{title: DataConflict, message: json |> field("message", string)},
    );
  };
};

module RequestTimeoutHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({title: RequestTimeout, message: "Request timed out"});
  };
};

module FailedToFetchErrorHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({title: FailedToFetch, message: "Failed to fetch."});
  };
};

module RequestCancelledErrorHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({title: RequestCancelled, message: "Request Cancelled"});
  };
};

module OperationAbortedHandler = {
  let execute = (): Error.t => {
    Error.DefaultError({title: OperationAborted, message: "Operation Aborted"});
  };
};

module CorsHandler = {
  let execute = (data: string): Error.t => {
    switch (Env.getWorkingEnv()) {
    | Production => Error.DefaultError({title: FailedToFetch, message: "Failed to fetch."})
    | _ => Error.DefaultError({title: CorsError, message: data})
    };
  };
};

module NoContentHandler = {
  let execute = (~_json: Js.Json.t): NoContent.t => {
    {title: "Resource Created", message: "Resource successfully created"};
  };
};

module PostApiHandler = {
  let execute = (~json: Js.Json.t): ApiResponse.t =>
    Json.Decode.{
      status: json |> field("status", int),
      message: json |> field("message", string),
    };
};
