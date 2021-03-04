exception RequestTimedout;
exception FailedToFetch;
exception RequestCancelled;
exception OperationAborted;
exception Cors(string);
exception UnhandledError(Js.Promise.error);