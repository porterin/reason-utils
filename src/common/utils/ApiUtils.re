exception PromiseException(Js.Promise.error);

let handleAPIRequest =
    (
      apiRequest: _ => Js.Promise.t(Belt.Result.t('a, 'b)),
      onSuccess: 'a => unit,
      onError: 'b => unit,
    ) => {
  Js.Promise.(
    apiRequest()
    |> then_((result: Belt.Result.t('a, 'b)) => {
         Belt.Result.(
           switch (result) {
           | Ok(data) => resolve(onSuccess(data))
           | Error(err) => resolve(onError(err))
           }
         )
       })
    |> catch(err => {
         let _ = SentryRe.capturePromiseError(err);
         reject(PromiseException(err))
       })
    |> ignore
  );
};

let resolveRepoResponse = (handleResponse: _ => option(Js.Promise.t(Belt.Result.t('a, 'b)))) => {
  switch (handleResponse()) {
  | Some(data) => data
  | None =>
    Js.Promise.resolve(
      Belt.Result.Error(
        Error.DefaultError({
          type_: ErrorType.InternalServerError,
          title: "Internal Server Error",
          message: "Something went wrong",
        }),
      ),
    )
  };
};
