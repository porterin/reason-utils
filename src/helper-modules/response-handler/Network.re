let maxRetryCount = 3;
let maxTimeoutMs = 15000;

open PromiseHandler;

module NetworkUtils = {
  let getDefaultHeaders = (): Js.t('a) => {
    {"Content-Type": "application/json", "Accept": "application/json"};
  };
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
  PromiseHandler.resolvePromise(~promise, ~timeoutMs);
};

let postRequestV2 =
    (~requestUrl: string, ~payload: string, ~header: Js.t('a), ~timeoutMs=maxTimeoutMs, _unit)
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
  PromiseHandler.resolvePromise(~promise, ~timeoutMs);
};

let putRequest =
    (~requestUrl: string, ~payload: string, ~authToken: string, ~timeoutMs=maxTimeoutMs, _unit)
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
  PromiseHandler.resolvePromise(~promise, ~timeoutMs);
};

let deleteRequest =
    (~requestUrl: string, ~timeoutMs=maxTimeoutMs, __unit): Js.Promise.t(ResponseType.t) => {
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
  PromiseHandler.resolvePromise(~promise, ~timeoutMs);
};

let getRequestV2 =
    (~requestUrl: string, ~timeoutMs=maxTimeoutMs, ~retryCount=maxRetryCount, ())
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
  PromiseHandler.resolvePromiseWithRetry(~promiseGenerator, ~timeoutMs, ~retryCount);
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
  PromiseHandler.resolvePromiseWithRetry(~promiseGenerator, ~timeoutMs, ~retryCount);
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
  PromiseHandler.resolvePromiseWithRetry(~promiseGenerator, ~timeoutMs, ~retryCount);
};
