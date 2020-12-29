open OptionTypeUtils;

let getCellView = (cellData: CellDataType.t) => {
  switch (cellData) {
  | Text(data) =>
    <div
      className={"card-component__table-text-cell " ++ getStringFrmOptionalType(data.className)}>
      {React.string(data.content)}
    </div>
  | Action(data) =>
    <TertiaryButton
      className={"card-component__table-link-cell " ++ getStringFrmOptionalType(data.className)}
      onSelectCB={data.callback}>
      {React.string(data.content)}
    </TertiaryButton>
  };
};
let getRowView = (rowData: RowDataType.t) => {
  <div className="card-component__table-row">
    {rowData.row
     |> List.map((cellData: CellDataType.t) => getCellView(cellData))
     |> ReasonReactUtils.listToReactArray}
  </div>;
};

let getTableView = (tableData: list(RowDataType.t)) => {
  <div className="card-component__table-container">
    {tableData
     |> List.map((rowData: RowDataType.t) => getRowView(rowData))
     |> ReasonReactUtils.listToReactArray}
  </div>;
};
[@react.component]
let make = (~tableData: Loadable.t(list(RowDataType.t))) => {
  switch (tableData) {
  | Init => <div> {React.string("Initializing")} </div>
  | Loading(tableData) =>
    switch (tableData) {
    | Some(data) => getTableView(data)
    | None => <LoadingViewComponent />
    }
  | Live(tableData) => getTableView(tableData)
  | Error(error) => <ErrorDisplayComponent error />
  };
};
