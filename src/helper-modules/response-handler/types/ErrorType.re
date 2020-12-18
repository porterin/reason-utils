type t =
  | Custom(string)
  | UnprocessedEntity
  | NotAcceptableEntity
  | Unauthorized
  | Forbidden
  | InternalServerError
  | DataConflict
  | RequestTimeout
  | FailedToFetch
  | RequestCancelled
  | OperationAborted
  | Cors;