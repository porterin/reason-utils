[@react.component]
let make =
    (
      ~loadableData: FetchLoadable.t('a),
      ~children: _ => React.element,
      ~loadingData: React.element=<LoadingViewComponent />,
    ) => {
  switch (loadableData) {
  | _ => <ErrorDisplayComponent error />
  | Loading(_data) => loadingData
  | Live(data) => children(data)
  | Error(error) => <ErrorDisplayComponent error />
  };
};
