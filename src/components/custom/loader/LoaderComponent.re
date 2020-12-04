module type LoaderConfig = {type dataType;};

module LoaderComponent = (Config: LoaderConfig) => {
  
  type state = Loadable.t(Config.dataType);

  type action =
    | LoadData(option(Config.dataType))
    | LoadView(Config.dataType)
    | LoadErrorView(Error.t);

  let getInitialState = (): state => Loadable.Init;

  [@react.component]
  let make =
    (
      ~fetchData:
          unit => Js.Promise.t(Belt.Result.t(Config.dataType, Error.t)),
      ~initView=_ => <div> {React.string("Init...")} </div>,
      ~loadingView=_ => <LoadingViewComponent />,
      ~renderView: (Config.dataType, _ => unit) => React.element
    ) => {
      
    let (state, dispatch) =
      React.useReducer(
        (_state, action) =>
          switch (action) {
          | LoadData(data) => Loadable.Loading(data)
          | LoadView(data) => Live(data)
          | LoadErrorView(error) => Error(error)
          },
        getInitialState(),
      );

    React.useEffect0(() => {
      switch(state) {
        | Loadable.Init => dispatch(LoadData(None));
        | _ => ()
      };
       None;
    });  

    React.useEffect1(
      () => {
        switch(state) {
          | Loading(_data) => ApiUtils.handleAPIRequest(
            () => fetchData(),
            data => dispatch(LoadView(data)),
            message => dispatch(LoadErrorView(message)),
          );
          | _ => ()
        };
        None;
    },[|state|]);

    (
      switch (state) {
        | Init => initView()
        | Loading(_data) => loadingView()
        | Error(error) => <ErrorDisplayComponent error />
        | Live(result) => renderView(result, _ => dispatch(LoadData(None)))
      }
    );
  };
};

module LoaderComponentWithoutRefresh = (Config: LoaderConfig) => {
  module BaseLoaderComponent = LoaderComponent(Config);
  [@react.component]
  let make =
      (
        ~fetchData:
           unit => Js.Promise.t(Belt.Result.t(Config.dataType, Error.t)),
        ~initView=_ => <div> {React.string("Init...")} </div>,
        ~loadingView=_ => <LoadingViewComponent />,
        ~renderView: Config.dataType => React.element
      ) => {
    <BaseLoaderComponent
      fetchData
      initView
      loadingView
      renderView={(data, _onRefresh) => renderView(data)}
    />;
  };
};
