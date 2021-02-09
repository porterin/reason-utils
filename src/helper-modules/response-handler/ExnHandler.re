open Exception;

module type UndefinedErrorHandler = {
  let mapErrorsToExn: (Js.Promise.error) => exn
};

module UndefinedErrorHandler = {
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

  let mapErrorsToExn = (error: Js.Promise.error): exn => {
    Js.log("------undefined-error-handler------")
    Js.log("------js.promise.error |> toString------")
    Js.log(error |> toString)

    //Fetch throws the following exceptions when it fails to make network
    //calls. Failed to fetch is thrown in Chrome whereas NetworkError
    //when attempting to fetch resource is thrown in Firefox.
    //Reference: https://github.com/github/fetch/issues/310
    //Refernce: https://twitter.com/xinganwang/status/1189266788237885443?lang=en
    switch (error |> toString) {
      | "TypeError: Failed to fetch" // Chrome
      | "TypeError: NetworkError when attempting to fetch resource." // Firefox
      | "TypeError: A server with the specified hostname could not be found." // Safari
      | "TypeError: The internet connection appears to be offline" //Safari
      | "TypeError: The network connection was lost" //Safari and Firefox
      | "TypeError: Network request failed" // Windows
        => FailedToFetch
      | "TypeError: cancelled" => RequestCancelled
      | "AbortError: The operation was aborted" //Firefox
      | "TypeError: The operation couldn’t be completed. Software caused connection abort"  //Safari
      => OperationAborted
      | _ => isCors(error |> toString) ? Cors(error |> toString) : UnhandledError(error)
      };
  };
};

module type ExnHandler = {
    let mapErrorsToExn: (Js.Promise.error) => exn
};

module ExnHandler = {
  type exnPayload = {
     [@bs.as("RE_EXN_ID")]
     _RE_EXN_ID: string
  };

  external deserialzeErr: Js.Promise.error => exnPayload= "%identity";

  // the regex here extracts the exception name from the whole pattern 
  // for e.g RequestTimedout is extracted from the expresssion "Exception-Catalyst.RequestTimedout/3".
  let getExnString = (exn: string) => { 
      exn 
      |> Js.String.match([%re "/(\.)(.*?)(?=\/)/"]) 
      |> result => switch(result) {
        | None => "not_found"
        | Some(result) => result[2]
      }
  }

  let mapErrorStrToExn = (error: Js.Promise.error, exn: string) => {
    switch (exn -> getExnString) {
      | "RequestTimedout" => RequestTimedout
      | _ => UnhandledError(error)
    };
  };

  let mapErrorToExn = (error: Js.Promise.error): exn => {
    Js.log("------Js.promise.error------")
    Js.log(error)
    let exnPayload = error |> deserialzeErr
    Js.log("-----exception-payload------")
    Js.log(exnPayload)
    Js.log("-----Js.typeof-----")
    Js.log(Js.typeof(exnPayload._RE_EXN_ID))
    switch (Js.typeof(exnPayload._RE_EXN_ID)) {
    | "undefined" => UndefinedErrorHandler.mapErrorsToExn(error)
    | _ => mapErrorStrToExn(error, exnPayload._RE_EXN_ID)
    };
  };
};
