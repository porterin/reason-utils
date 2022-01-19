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
      <TableHeader className="table-header" columns buildHeaderCell=HeaderCellBuilder.execute />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((index, rData) =>
              <TableRow className="" key={index->string_of_int}>
                {TableRowBuilder.execute(rData, columns)}
              </TableRow>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
