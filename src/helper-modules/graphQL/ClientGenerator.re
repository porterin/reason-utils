let make = (~url: string) =>
  ReasonUrql.Client.make(
    ~url,
    ~fetchOptions=
      ReasonUrql.Client.FetchOpts(
        Fetch.RequestInit.make(
          ~method_=Post,
          ~mode=CORS,
          ~headers=Fetch.HeadersInit.make({"Authorization": "Bearer <token>"}), //REMOVE `headers` on staging
          ~credentials=Include,
          (),
        ),
      ),
    (),
  );
