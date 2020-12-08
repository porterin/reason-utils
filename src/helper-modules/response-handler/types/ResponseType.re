type t =
  | Success(Js.Json.t)
  | SuccessWithNoContent(Js.Json.t)
  | UnprocessedEntity(Js.Json.t)
  | NotAcceptableEntity(Js.Json.t)
  | Unauthorized(Js.Json.t)
  | Forbidden(Js.Json.t)
  | InternalServerError(Js.Json.t)
  | DataConflict(Js.Json.t)
  | TimedoutError
  | FailedToFetch
  | RequestCancelled ;
