exception RequestTimedout;
exception FailedToFetch;
exception RequestCancelled;
exception PromiseException(Js.Promise.error);

let fromString = (exn: string) => {
  switch (exn) {
  | "Exception.RequestTimedout" => RequestTimedout
  | _ =>
    ErrorUtils.raiseError(
      ~path="Exception.fromString",
      ~message="No predefined Exception string found: ",
      ~value=exn,
    )
  };
};

module UnhandledExceptionHandler = {
  [@bs.send] external toString: Js.Promise.error => string = "toString";

  let resolveException = (error: Js.Promise.error): exn => {
    //Fetch throws the following exceptions when it fails to make network
    //calls. Failed to fetch is thrown in Chrome whereas NetworkError
    //when attempting to fetch resource is thrown in Firefox.
    //Reference: https://github.com/github/fetch/issues/310
    switch (error |> toString) {
    | "TypeError: Failed to fetch" // Chrome
    | "TypeError: NetworkError when attempting to fetch resource." // Firefox
    | "TypeError: A server with the specified hostname could not be found." // Safari
    | "TypeError: Network request failed" // Windows
      => FailedToFetch
    | "TypeError: cancelled" => RequestCancelled
    | _ => PromiseException(error)
    };
  };
};

module ExceptionHandler = {
  external errorToPair: Js.Promise.error => (string, int) = "%identity";

  let resolveException = (error: Js.Promise.error): exn => {
    let errorString = error |> errorToPair |> fst;
    switch (Js.typeof(errorString)) {
    | "undefined" => UnhandledExceptionHandler.resolveException(error)
    | _ => fromString(errorString)
    };
  };
};
