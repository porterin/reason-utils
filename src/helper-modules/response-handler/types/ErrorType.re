type t =
  | Custom(string)
  | UnprocessedEntity(option(string))
  | BadRequest
  | NotAcceptableEntity
  | Unauthorized
  | Forbidden
  | InternalServerError
  | DataConflict
  | RequestTimeout
  | FailedToFetch
  | RequestCancelled
  | OperationAborted
  | CorsError;
