let maxRetryCount = 3;
let maxTimeoutMs = 15000;

exception NetworkRequestFailed;

module NetworkUtils = {
  let getDefaultHeaders = (): Js.t('a) => {
    {"Content-Type": "application/json", "Accept": "application/json"};
  };
};

let handlePromiseTimeout =
    (~promise: Js.Promise.t('a), ~timeoutMs: int): Js.Promise.t('a) => {
  let timeoutPromise =
    Js.Promise.make((~resolve as _, ~reject) => {
      let _timeoutId =
        Js.Global.setTimeout(
          () => reject(. Exception.RequestTimedout),
          timeoutMs,
        );
      ();
    });
  Js.Promise.race([promise, timeoutPromise] |> Array.of_list);
};

let rec promiseWithTimeout =
        (
          ~promiseGenerator: unit => Js.Promise.t(Fetch.response),
          ~timeoutMs: int,
          ~retryCount: int,
        ) => {
  let finalPromise =
    handlePromiseTimeout(~promise=promiseGenerator(), ~timeoutMs);
  finalPromise
  |> Js.Promise.catch(error =>
       switch (
         retryCount,
         Exception.PromiseToExceptionMap.getException(error),
       ) {
       | (count, Exception.RequestTimedout) when count > 0 =>
         promiseWithTimeout(
           ~promiseGenerator,
           ~timeoutMs,
           ~retryCount={
             count - 1;
           },
         )
       | _ => finalPromise
       }
     );
};

let resolvePromiseWithTimeout = (promise: Js.Promise.t(Fetch.response)) => {
  promise
  |> Js.Promise.then_(ResponseHandler.ResponseWrapper.execute)
  |> Js.Promise.catch(error =>
       switch (Exception.PromiseToExceptionMap.getException(error)) {
       | Exception.RequestTimedout =>
         Js.Promise.resolve(ResponseType.TimedoutError)
       | _ => raise(NetworkRequestFailed)
       }
     );
};

let postRequest =
    (~requestUrl: string, ~payload: string, ~timeoutMs=maxTimeoutMs, _unit)
    : Js.Promise.t(ResponseType.t) => {
  let promise =
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=Fetch.BodyInit.make(payload),
        ~headers=Fetch.HeadersInit.make(NetworkUtils.getDefaultHeaders()),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  resolvePromiseWithTimeout(handlePromiseTimeout(~promise, ~timeoutMs));
};

let postRequestV2 =
    (
      ~requestUrl: string,
      ~payload: string,
      ~header: Js.t('a),
      ~timeoutMs=maxTimeoutMs,
      _unit,
    )
    : Js.Promise.t(ResponseType.t) => {
  let promise =
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=Fetch.BodyInit.make(payload),
        ~headers=
          Fetch.HeadersInit.make(
            Js.Obj.assign(
              {
                "Content-Type": "application/json",
                "Accept": "application/json",
                "Access-Control-Allow-Origin": "*",
                "Access-Control-Allow-Credentials": true,
              },
              header,
            ),
          ),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  resolvePromiseWithTimeout(handlePromiseTimeout(~promise, ~timeoutMs));
};

let putRequest =
    (
      ~requestUrl: string,
      ~payload: string,
      ~authToken: string,
      ~timeoutMs=maxTimeoutMs,
      _unit,
    )
    : Js.Promise.t(ResponseType.t) => {
  let promise =
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Put,
        ~body=Fetch.BodyInit.make(payload),
        ~headers=
          Fetch.HeadersInit.make({
            "Content-Type": "application/json",
            "Accept": "application/json",
            "DRIVER_AUTH_TOKEN": authToken,
          }),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  resolvePromiseWithTimeout(handlePromiseTimeout(~promise, ~timeoutMs));
};

let deleteRequest =
    (~requestUrl: string, ~timeoutMs=maxTimeoutMs, __unit)
    : Js.Promise.t(ResponseType.t) => {
  let promise =
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Delete,
        ~headers=Fetch.HeadersInit.make(NetworkUtils.getDefaultHeaders()),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  resolvePromiseWithTimeout(handlePromiseTimeout(~promise, ~timeoutMs));
};

let getRequestV2 =
    (
      ~requestUrl: string,
      ~timeoutMs=maxTimeoutMs,
      ~retryCount=maxRetryCount,
      (),
    )
    : Js.Promise.t(ResponseType.t) => {
  let promiseGenerator = () =>
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Get,
        ~headers=Fetch.HeadersInit.make(NetworkUtils.getDefaultHeaders()),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  promiseWithTimeout(~promiseGenerator, ~timeoutMs, ~retryCount)
  |> resolvePromiseWithTimeout;
};

let getRequestV3 =
    (
      ~requestUrl: string,
      ~authToken: string,
      ~timeoutMs=maxTimeoutMs,
      ~retryCount=maxRetryCount,
      (),
    )
    : Js.Promise.t(ResponseType.t) => {
  let promiseGenerator = () =>
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Get,
        ~headers=
          Fetch.HeadersInit.make({
            "Content-Type": "application/json",
            "DRIVER_AUTH_TOKEN": authToken,
          }),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  promiseWithTimeout(~promiseGenerator, ~timeoutMs, ~retryCount)
  |> resolvePromiseWithTimeout;
};

let getRequestV4 =
    (
      ~requestUrl: string,
      ~authToken: string,
      ~timeoutMs=maxTimeoutMs,
      ~retryCount=maxRetryCount,
      (),
    )
    : Js.Promise.t(ResponseType.t) => {
  let promiseGenerator = () =>
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Get,
        ~headers=
          Fetch.HeadersInit.make({
            "Content-Type": "application/json",
            "driver-auth-token": authToken,
          }),
        ~credentials=Include,
        ~mode=CORS,
        (),
      ),
    );
  promiseWithTimeout(~promiseGenerator, ~timeoutMs, ~retryCount)
  |> resolvePromiseWithTimeout;
};
