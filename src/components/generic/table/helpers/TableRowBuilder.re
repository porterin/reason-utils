let execute = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.mapi((key, columnHeader: TableSchema.t('a)) =>
       <TableCellComponent key={key->string_of_int} cell={columnHeader.accessor(rowData)} />
     )
  |> ReasonReactUtils.listToReactArray;
};
