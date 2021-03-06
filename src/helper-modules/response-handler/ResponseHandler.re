module type ResponseWrapperConfig = {let execute: Fetch.response => Js.Promise.t(ResponseType.t);
};

module ResponseWrapper = {
  let parseSuccess = (response: Fetch.response) => {
    response
    |> Fetch.Response.json
    |> Js.Promise.then_(result => Js.Promise.resolve(ResponseType.Success(result)));
  };

  let parseUnprocessedError = (response: Fetch.response) => {
    response
    |> Fetch.Response.json
    |> Js.Promise.then_(result => Js.Promise.resolve(ResponseType.UnprocessedEntity(result)));
  };

  let parseNotAcceptableError = (response: Fetch.response) => {
    response
    |> Fetch.Response.json
    |> Js.Promise.then_(result => Js.Promise.resolve(ResponseType.NotAcceptableEntity(result)));
  };

  let parseDataConflictError = (response: Fetch.response) => {
    response
    |> Fetch.Response.json
    |> Js.Promise.then_(result => Js.Promise.resolve(ResponseType.DataConflict(result)));
  };

  let execute = (response: Fetch.response): Js.Promise.t(ResponseType.t) => {
    ResponseType.(
      switch (Fetch.Response.status(response)) {
      | 200
      | 201
      | 301
      | 302 => parseSuccess(response)
      | 204 =>
        Js.Promise.resolve(
          SuccessWithNoContent(
            [%bs.raw
              {|
            {
              "title": "Success",
              "message": "The operation was successfully completed"
            }
          |}
            ],
          ),
        )
      | 422 => parseUnprocessedError(response)
      | 406 => parseNotAcceptableError(response)
      | 401 =>
        Js.Promise.resolve(
          Unauthorized(
            [%bs.raw
              {|
            {
              "title": "Unauthorized",
              "message": "You are not authenticated for the operation"
            }
          |}
            ],
          ),
        )
      | 403 =>
        Js.Promise.resolve(
          Forbidden(
            [%bs.raw
              {|
              {
                "title": "Forbidden",
                "message": "You are not authorized for the operation"
              }
            |}
            ],
          ),
        )
      | 409 => parseDataConflictError(response)
      | _ =>
        Js.Promise.resolve(
          InternalServerError(
            [%bs.raw
              {|
            {
              "title": "Internal Server Error",
              "message": "Something went wrong"
            }
          |}
            ],
          ),
        )
      }
    );
  };
};

module type ErrorConverterConfig = {
  type t;
  let execute: ResponseType.t => option(t);
};

module DefaultErrorConverter = {
  type t = Error.t;
  let execute = (data: ResponseType.t) => {
    switch (data) {
    | UnprocessedEntity(data) =>
      Some(GenericResponseMapper.UnprocessedErrorHandler.execute(~json=data))
    | NotAcceptableEntity(data) =>
      Some(GenericResponseMapper.NotAcceptableErrorHandler.execute(~json=data))
    | Unauthorized(_data) =>
      Env.getHostName()
      |> (
        hostname =>
          hostname
          ++ "/administrators/sign_in"
          |> (
            url =>
              {
                JsBindings.redirect(url, "_parent");
              }
              |> (() => None)
          )
      )
    | Forbidden(data)
    | InternalServerError(data) =>
      Some(GenericResponseMapper.ForbiddenErrorHandler.execute(~json=data))
    | DataConflict(data) =>
      Some(GenericResponseMapper.DataConflictErrorHandler.execute(~json=data))
    | FailedToFetch => Some(GenericResponseMapper.FailedToFetchErrorHandler.execute())
    | RequestCancelled => Some(GenericResponseMapper.RequestCancelledErrorHandler.execute())
    | UnhandledError(error) => {
      //we ensure that all the unhandled errors come here
      Js.log("---response-handler---")
      Js.log(error)
      SentryRe.capturePromiseError(error) |> ignore
      None
    }
    | _ => None
    };
  };
};

module type ResponseConverterConfig = {
  type responseDataType;
  let execute: Js.Json.t => responseDataType;
};

module ResponseConverter =
       (
         ResponseConverterConfig: ResponseConverterConfig,
         ErrorConverterConfig: ErrorConverterConfig,
       ) => {
  let execute =
      (response: ResponseType.t)
      : option(
          Js.Promise.t(
            Belt.Result.t(ResponseConverterConfig.responseDataType, ErrorConverterConfig.t),
          ),
        ) => {
    switch (response) {
    | Success(data)
    | SuccessWithNoContent(data) =>
      Some(Js.Promise.resolve(Belt.Result.Ok(ResponseConverterConfig.execute(data))))
    | _ =>
      switch (ErrorConverterConfig.execute(response)) {
      | Some(error) => Some(Js.Promise.resolve(Belt.Result.Error(error)))
      | None => None
      }
    };
  };
};

module type DriverResponseConverterConfig = {
  type responseDataType;
  let execute: (Js.Json.t, string) => responseDataType;
};

module DriverResponseConverter =
       (
         ResponseConverterConfig: DriverResponseConverterConfig,
         ErrorConverterConfig: ErrorConverterConfig,
       ) => {
  open ResponseType;
  let execute =
      (response: t, msisdn: CommonTypes.msisdn)
      : option(
          Js.Promise.t(
            Belt.Result.t(ResponseConverterConfig.responseDataType, ErrorConverterConfig.t),
          ),
        ) => {
    switch (response) {
    | Success(data)
    | SuccessWithNoContent(data) =>
      Some(Js.Promise.resolve(Belt.Result.Ok(ResponseConverterConfig.execute(data, msisdn))))
    | _ =>
      switch (ErrorConverterConfig.execute(response)) {
      | Some(error) => Some(Js.Promise.resolve(Belt.Result.Error(error)))
      | None => None
      }
    };
  };
};