module type DataFetcherConfig = {type dataType;};

module DataFetcher = (Config: DataFetcherConfig) => {
  let useDataFetcher = (
    fetchData: unit => Js.Promise.t(Belt.Result.t(Config.dataType, Error.t))
  ) => {

    let (state, setState) =   React.useState(_ => Loadable.Init);
    
    React.useEffect0(() => {
      switch(state) {
        | Loadable.Init => setState(_ => Loading(None))
        | _ => ()
      };
       None;
    }); 

    React.useEffect1(() => {
      switch(state) {
        | Loading(_data) => ApiUtils.handleAPIRequest(
          () => fetchData(),
          data => setState(_ => Live(data)),
          error => setState(_ => Error(error))
        );
        | _ => ()
      };
      None;
    } ,[|state|])

    state
  }
}

