module type PromiseHandler = {
  let resolvePromise:
    (~promise: Js.Promise.t(Fetch.response), ~timeoutMs: int) => Js.Promise.t(ResponseType.t);
  let resolvePromiseWithRetry:
    (
      ~promiseGenerator: unit => Js.Promise.t(Fetch.response),
      ~timeoutMs: int,
      ~retryCount: int
    ) =>
    Js.Promise.t(ResponseType.t);
};

module PromiseHandler: PromiseHandler = {
  open ExnHandler;

  let promiseWithTimeout = (promise: Js.Promise.t('a), timeoutMs: int): Js.Promise.t('a) => {
    let timeoutPromise =
      Js.Promise.make((~resolve as _, ~reject) => {
        let _timeoutId =
          Js.Global.setTimeout(() => reject(. Exception.RequestTimedout), timeoutMs);
        ();
      });
    Js.Promise.race([promise, timeoutPromise] |> Array.of_list);
  };

  let rec promiseWithTimeoutAndRetry =
          (
            promiseGenerator: unit => Js.Promise.t(Fetch.response),
            timeoutMs: int,
            retryCount: int,
          ) => {
    let finalPromise = promiseWithTimeout(promiseGenerator(), timeoutMs);
    finalPromise
    |> Js.Promise.catch(error =>
         switch (retryCount, ExnHandler.mapErrorToExn(error)) {
         | (count, Exception.RequestTimedout) when count > 0 =>
           promiseWithTimeoutAndRetry(promiseGenerator, timeoutMs, count - 1)
         | _ => finalPromise
         }
       );
  };

   //we ensure that all the unhandled errors are captured as ResponseType.UnhandledError 
   //so that the original Js.Promise.error is intact
  let mapExnToResponseType = (error: Js.Promise.error, exp: exn) => {
    switch (exp) {
    | Exception.RequestTimedout => Js.Promise.resolve(ResponseType.RequestTimeout)
    | Exception.FailedToFetch => Js.Promise.resolve(ResponseType.FailedToFetch)
    | Exception.RequestCancelled => Js.Promise.resolve(ResponseType.RequestCancelled)
    | Exception.OperationAborted => Js.Promise.resolve(ResponseType.OperationAborted)
    | Exception.Cors(data) => Js.Promise.resolve(ResponseType.Cors(data))
    | Exception.UnhandledError(promiseError) => Js.Promise.resolve(ResponseType.UnhandledError(promiseError))
    | _ => Js.Promise.resolve(ResponseType.UnhandledError(error))
    };
  };

  let resolveResponse = (promise: Js.Promise.t(Fetch.response)) => {
    promise
    |> Js.Promise.then_(ResponseHandler.ResponseWrapper.execute)
    |> Js.Promise.catch((error) => {
        error
        |> ExnHandler.mapErrorToExn
        |> mapExnToResponseType(error)
    });
  };

  let resolvePromise = (~promise: Js.Promise.t(Fetch.response), ~timeoutMs) => {
    promise->promiseWithTimeout(timeoutMs)->resolveResponse;
  };

  let resolvePromiseWithRetry =
      (~promiseGenerator: unit => Js.Promise.t(Fetch.response), ~timeoutMs, ~retryCount) => {
    promiseGenerator->promiseWithTimeoutAndRetry(timeoutMs, retryCount) |> resolveResponse;
  };
};
