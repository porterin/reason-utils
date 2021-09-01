let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.map((columnHeader: TableSchema.t('a)) =>
       <TableCellComponent cell=columnHeader.accessor(rowData) />
     )
  |> ReasonReactUtils.listToReactArray
};


[@react.component]
let make =
    (
      ~columns: list(TableSchema.t('a)),
      ~rowData: list('a),
      ~className: string="",
    ) => {
  <>
    <Table className={"table " ++ className} stickyHeader=true>

       <TableHeader className="table-header" columns=columns />

        <TableBody className="table-body">
          {rowData
           |> List.map(rData =>
                <TableRow className="">
                  {getTableRow(rData, columns)}
                </TableRow>
              )
            |> ReasonReactUtils.listToReactArray
          }
        </TableBody>

      </Table>
  </>;
};
