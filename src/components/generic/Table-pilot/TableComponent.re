let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.mapi((index, columnHeader: TableSchema.t('a)) =>
       <TableCellComponent
         key={"table-cell" ++ string_of_int(index)}
         cell={columnHeader.accessor(rowData)}
       />
     )
  |> ReasonReactUtils.listToReactArray;
};

[@react.component]
let make = (~columns: list(TableSchema.t('a)), ~rowData: list('a), ~className: string="") => {
  <>
    <Table className={"table " ++ className}>
      <TableHeader className="table-header" columns />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((index, rData) =>
              <TableRow key={"table-row" ++ string_of_int(index)} className="">
                {getTableRow(rData, columns)}
              </TableRow>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
