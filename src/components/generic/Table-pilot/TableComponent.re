let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.mapi((index, columnHeader: TableSchema.t('a)) =>
       <TableCellComponent key={index->string_of_int} cell={columnHeader.accessor(rowData)} />
     )
  |> ReasonReactUtils.listToReactArray;
};

[@react.component]
let make =
    (
      ~columns: list(TableSchema.t('a)),
      ~rowData: list('a),
      ~className: string="",
      ~is_sticky_header: bool=false,
    ) => {
  <>
    <Table className={"table " ++ className} is_sticky_header>
      <TableHeader className="table-header" columns />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((index, rData) =>
              <TableRow className="" key={index->string_of_int}>
                {getTableRow(rData, columns)}
              </TableRow>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
