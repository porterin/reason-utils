let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.map((columnHeader: TableSchema.t('a)) =>
       <TableCellComponent cell={columnHeader.accessor(rowData)} />
     )
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

module TableHeader = { //added one empty cell in header row
  let getColumnHeaders =
      (~columns: list(TableSchema.t('a))): ReasonReact.reactElement => {
    columns
    |> List.map((columnHeader: TableSchema.t('a)) =>
         switch (columnHeader.column) {
         | Text(text) =>
           <MaterialUi.TableCell> {React.string(text)} </MaterialUi.TableCell>
         | Custom(renderFn) =>
           <MaterialUi.TableCell> {renderFn()} </MaterialUi.TableCell>
         }
       )
    |> ReasonReactUtils.listToReactArray;
  };

  let buildTableHeader =
      (~className: string, ~columns: list(TableSchema.t('a))) => {
    <MaterialUi.TableHead>
      <TableRow className> <MaterialUi.TableCell />{getColumnHeaders(~columns)} </TableRow>
    </MaterialUi.TableHead>;
  };

  [@react.component]
  let make = (~className: string, ~columns: list(TableSchema.t('a))) =>
    buildTableHeader(~className, ~columns);
};

[@react.component]
let make =
    (
      ~columns: list(TableSchema.t('a)),
      ~rowData: list(('a, TableCell.t)),
      ~className: string="",
    ) => {
  <>
    <Table className={"table " ++ className}>
      <TableHeader className="table-header" columns />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((key, (rData, collapsing_cell_data)) =>
              <>
                <TableRow className="" key={key->string_of_int}>
                    <TableCellComponent cell=Custom(_ => <Icon.KeyboardArrowDownIconIcon />) colSpan=7 />
                  {getTableRow(rData, columns)}
                </TableRow>
                <TableRow className="">
                  {getTableRow(rData, columns)}
                  <TableCellComponent cell=collapsing_cell_data colSpan=7 />
                </TableRow>
              </>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
