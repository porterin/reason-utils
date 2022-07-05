type t =
  | Success(Js.Json.t)
  | SuccessWithNoContent(Js.Json.t)
  | BadRequest(Js.Json.t)
  | UnprocessedEntity(Js.Json.t)
  | NotAcceptableEntity(Js.Json.t)
  | Unauthorized(Js.Json.t)
  | Forbidden(Js.Json.t)
  | InternalServerError(Js.Json.t)
  | DataConflict(Js.Json.t)
  | RequestTimeout
  | FailedToFetch
  | RequestCancelled
  | OperationAborted
  | Cors(string)
  | UnhandledError(Js.Promise.error);
