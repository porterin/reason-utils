let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.map((columnHeader: TableSchema.t('a)) =>
       <TableCellComponent cell={columnHeader.accessor(rowData)} />
     )
  |> ReasonReactUtils.listToReactArray;
};

let getRowHeader = (rowHeader: GroupTableSchema.t('a)) => {
  [
    <TableRow className="table__row-header">
      {switch (rowHeader.label) {
       | Text(title) => <div className="table__row-header-title">{React.string(title)}</div>
       | Custom(renderFn) => renderFn()
       }}
    </TableRow>,
  ]
  |> ReasonReactUtils.listToReactArray;
};

let getRows =
    (rowsData: GroupTableSchema.t('a), columns: list(TableSchema.t('a))) => {
  rowsData.rows
    |> List.map(rData =>
       <TableRow className=""> {getTableRow(rData, columns)} </TableRow>
     )
    |> ReasonReactUtils.listToReactArray;
};

let getTableBody = (rowData: list(GroupTableSchema.t('a)), columns: list(TableSchema.t('a))) => {
  rowData
    |> List.map((rdata: GroupTableSchema.t('a)) => {
         let rowHeader = getRowHeader(rdata);
         let rows = getRows(rdata, columns);
         [rowHeader, rows];
       })
    |> List.flatten
    |> Array.of_list
};

[@react.component]
let make =
    (
      ~columns: list(TableSchema.t('a)),
      ~rowData: list(GroupTableSchema.t('a)),
      ~className: string="",
    ) => {
  <>
    <Table className={"table " ++ className}>
      <TableHeader 
        className="table-header" 
        columns 
        buildHeaderCell=HeaderCellBuilder.execute
      />
      <TableBody className="table-body">
        {getTableBody(rowData, columns)}
      </TableBody>
    </Table>
  </>;
};
