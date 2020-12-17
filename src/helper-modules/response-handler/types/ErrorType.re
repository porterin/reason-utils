type t =
  | Success
  | SuccessWithNoContent
  | UnprocessedEntity
  | NotAcceptableEntity
  | Unauthorized
  | Forbidden
  | InternalServerError
  | DataConflict
  | TimedoutError
  | FailedToFetch
  | RequestCancelled
  | OperationAborted
  | Cors;
