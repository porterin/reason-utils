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
          title: InternalServerError,
          message: "Something went wrong",
        }),
      ),
    )
  };
};
