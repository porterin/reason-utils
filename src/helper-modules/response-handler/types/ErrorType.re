type t =
  | Custom(string)
  | UnprocessedEntity(option(string))
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
