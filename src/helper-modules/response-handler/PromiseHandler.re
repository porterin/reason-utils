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
         switch (retryCount, Exception.ExceptionHandler.resolveException(error)) {
         | (count, Exception.RequestTimedout) when count > 0 =>
           promiseWithTimeoutAndRetry(promiseGenerator, timeoutMs, count - 1)
         | _ => finalPromise
         }
       );
  };

  let mapExceptionsToErrors = (exp: exn) => {
    switch (exp) {
    | Exception.RequestTimedout => Js.Promise.resolve(ResponseType.TimedoutError)
    | Exception.FailedToFetch => Js.Promise.resolve(ResponseType.FailedToFetch)
    | Exception.RequestCancelled => Js.Promise.resolve(ResponseType.RequestCancelled)
    | Exception.OperationAborted => Js.Promise.resolve(ResponseType.OperationAborted)
    | Exception.Cors(data) => Js.Promise.resolve(ResponseType.Cors(data))
    | _ => raise(exp)
    };
  };

  let resolveResponse = (promise: Js.Promise.t(Fetch.response)) => {
    promise
    |> Js.Promise.then_(ResponseHandler.ResponseWrapper.execute)
    |> Js.Promise.catch(error =>
         Exception.ExceptionHandler.resolveException(error)->mapExceptionsToErrors
       );
  };

  let resolvePromise = (~promise: Js.Promise.t(Fetch.response), ~timeoutMs) => {
    promise->promiseWithTimeout(timeoutMs)->resolveResponse;
  };

  let resolvePromiseWithRetry =
      (~promiseGenerator: unit => Js.Promise.t(Fetch.response), ~timeoutMs, ~retryCount) => {
    promiseGenerator->promiseWithTimeoutAndRetry(timeoutMs, retryCount) |> resolveResponse;
  };
};
