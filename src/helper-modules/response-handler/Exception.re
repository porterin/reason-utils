exception RequestTimedout;
exception FailedToFetch;
exception RequestCancelled;
exception OperationAborted;
exception Cors;
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

module type UnhandledExceptionHandler = {
    let resolveException: (Js.Promise.error) => exn
};

module UnhandledExceptionHandler = {
  [@bs.send] external toString: Js.Promise.error => string = "toString";

  let isCors = (errorString) => {
    let match = Js.String.match(
      [%re "/(TypeError: Origin https:\/\/)(([a-z]+)||(([a-z]+)\-([a-z]+)\-\d))(\.)(porter)(\.)(in)( is not allowed by Access-Control-Allow-Origin)/"],
        errorString
    )
    switch(match) {
      | Some(_arr) => true
      | None => false
    }
  }

  let resolveException = (error: Js.Promise.error): exn => {
    //Fetch throws the following exceptions when it fails to make network
    //calls. Failed to fetch is thrown in Chrome whereas NetworkError
    //when attempting to fetch resource is thrown in Firefox.
    //Reference: https://github.com/github/fetch/issues/310
    //Refernce: https://twitter.com/xinganwang/status/1189266788237885443?lang=en
    switch (error |> toString) {
      | "TypeError: Failed to fetch" // Chrome
      | "TypeError: NetworkError when attempting to fetch resource." // Firefox
      | "TypeError: A server with the specified hostname could not be found." // Safari
      | "TypeError: The Internet connection appears to be offline" //Safari
      | "TypeError: The network connection was lost" //Safari and Firefox
      | "TypeError: Network request failed" // Windows
        => FailedToFetch
      | "TypeError: cancelled" => RequestCancelled
      | "AbortError: The operation was aborted" //Firefox
      | "TypeError: The operation couldn’t be completed. Software caused connection abort"  //Safari
      => OperationAborted
      | _ => isCors(error |> toString) ? Cors : PromiseException(error)
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
