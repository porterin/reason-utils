type subAction('a) =
  | Load(option('a))
  | OnLoaded('a)
  | LoadErrorView(Error.t);

let mapLoadableToAction = (subAction: subAction('a)) => {
  switch (subAction) {
  | Load(data) => FetchLoadable.Loading(data)
  | OnLoaded(data) => FetchLoadable.Live(data)
  | LoadErrorView(error) => FetchLoadable.Error(error)
  };
};
