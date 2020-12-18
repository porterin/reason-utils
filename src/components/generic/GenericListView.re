module type Record = {type obj;};

module Make = (Cmp: Record) => {
  type t = {
    recs: list(Cmp.obj),
    offset: option(int),
  };
  type loadableType = FetchLoadable.t(t);
  type state = {
    data: loadableType,
    fetchMore: bool,
  };
  type actions =
    | SetData(loadableType)
    | SetError(Error.t)
    | UpdateList(loadableType, bool);

  let reducer = (state: state, action: actions) =>
    switch (action) {
    | SetData(data) => {...state, data}
    | SetError(error) => {...state, data: FetchLoadable.Error(error)}
    | UpdateList(data, fetchMore) => {data, fetchMore}
    };

  [@react.component]
  let make =
      (
        ~columns: list(TableSchema.t('a)),
        ~fetchData: (option(int), t => unit, Error.t => unit) => unit,
      ) => {
    let initialState = {data: FetchLoadable.Loading(None), fetchMore: true};
    let (state, dispatch) = React.useReducer(reducer, initialState);

    let setLoading = () => {
      switch (state.data) {
      | FetchLoadable.Live(list)
      | FetchLoadable.Loading(Some(list)) =>
        dispatch(SetData(FetchLoadable.Loading(Some(list))))
      | _ => dispatch(SetData(FetchLoadable.Loading(None)))
      };
    };

    let fetchExistingSessions = () =>
      switch (state.data) {
      | FetchLoadable.Loading(Some(prevList))
      | FetchLoadable.Live(prevList) => prevList.recs
      | _ => []
      };

    let getOffset = (): option(int) =>
      switch (state.data) {
      | FetchLoadable.Loading(Some(data))
      | FetchLoadable.Live(data) => data.offset
      | _ => None
      };

    let fetchData = () => {
      fetchData(
        getOffset(),
        data =>
          dispatch(
            UpdateList(
              FetchLoadable.Live({
                recs: fetchExistingSessions() @ data.recs,
                offset: data.offset,
              }),
              List.length(data.recs) !== 0,
            ),
          ),
        error => dispatch(SetError(error)),
      );
    };

    React.useEffect1(
      () => {
        switch (state.data) {
        | FetchLoadable.Loading(_data) => fetchData()
        | _ => ()
        };
        None;
      },
      [|state.data|],
    );

    let onScrollEndCallback = () => {
      switch (state.data) {
      | FetchLoadable.Live(_) when state.fetchMore => setLoading()
      | _ => ()
      };
    };

    <>
      {switch (state.data) {
       | Live(data) =>
         <Scrollable height="100%" onScrollEndCallback>
           <TableComponent columns className="order-table" rowData={data.recs} />
         </Scrollable>
       | FetchLoadable.Loading(Some(data)) =>
         <Scrollable height="100%" onScrollEndCallback={() => ()}>
           <TableComponent columns className="order-table" rowData={data.recs} />
         </Scrollable>
       | Loading(_data) => <LoadingViewComponent />
       | Error(error) => <ReloadableErrorDisplayComponent error />
       }}
    </>;
  };
};
