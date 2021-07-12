let maxRetryCount = 3;
let maxTimeoutMs = 15000;

open PromiseHandler;

module HeaderUtils = {
  let defaultHeaders = {
    "Content-Type": "application/json",
  };

  let make = (headers: option(Js.t('a))) => {
    Belt.Option.mapWithDefault(headers, defaultHeaders, (headers) => {
        Js.Obj.assign(
          defaultHeaders,
          headers
        )
    }) -> Fetch.HeadersInit.make;
  };
}

let post =
    (
      ~requestUrl: string, 
      ~headers: option(Js.t('a))=?,
      ~payload: string, 
      ~timeoutMs=maxTimeoutMs, 
      _unit)
    : Js.Promise.t(ResponseType.t) => {
  let promise =
    Fetch.fetchWithInit(
      requestUrl,
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=Fetch.BodyInit.make(payload),
        ~headers=HeaderUtils.make(headers),
        ~mode=CORS,
        (),
      ),
    );
  PromiseHandler.resolvePromise(~promise, ~timeoutMs);
};

let get =
  (
    ~requestUrl: string,
    ~headers: option(Js.t('a))=?,
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
          ~headers=HeaderUtils.make(headers),
          ~mode=CORS,
          (),
        ),
      );
    PromiseHandler.resolvePromiseWithRetry(~promiseGenerator, ~timeoutMs, ~retryCount);
};