module type CardWrapperConfig = {
  type dataType;
  let getLoadingView: unit => TableDataType.t;
};

module CardWrapper = (CardConfig: CardWrapperConfig) => {
  [@react.component]
  let make =
      (
        ~data: Loadable.t(CardConfig.dataType),
        ~getSuccessData: CardConfig.dataType => TableDataType.t,
      ) => {
    switch (data) {
    | Init => <div> {React.string("Init")} </div>
    | Loading(_data) => <CardComponentV2 cardData={CardConfig.getLoadingView()} />
    | Live(liveData) => <CardComponentV2 cardData={getSuccessData(liveData)} />
    | Error(error) => <ErrorDisplayComponent error />
    };
  };
};
