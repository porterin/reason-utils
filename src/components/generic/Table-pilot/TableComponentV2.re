let getTableRow = (rowData: 't, columns: list(TableSchemaV2.t('a)), showVisible) => {
  columns
  |> List.mapi((index, columnHeader: TableSchemaV2.t('a)) =>
       <TableCellComponent
         key={index->string_of_int}
         cell={columnHeader.accessor(rowData)}
         is_visible={showVisible || !columnHeader.is_visible_only_on_hover}
       />
     )
  |> ReasonReactUtils.listToReactArray;
};

[@react.component]
let make =
    (
      ~columns: list(TableSchemaV2.t('a)),
      ~rowData: list('a),
      ~className: string="",
      ~is_sticky_header: bool=false,
    ) => {
  let (showVisible, setShowVisible) = React.useState(_ => (-1));
  <>
    <Table className={"table " ++ className} is_sticky_header>
      <TableHeader
        className="table-header" 
        columns 
        buildHeaderCell=((~columnHeader: TableSchemaV2.t('a), ~index) => {
          switch (columnHeader.column) {
          | Text(text) =>
            <MaterialUi.TableCell key={index->string_of_int}>
              {React.string(text)}
            </MaterialUi.TableCell>
          | Custom(renderFn) =>
            <MaterialUi.TableCell key={index->string_of_int}> {renderFn()} </MaterialUi.TableCell>
          }
        })
      />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((index, rData) =>
              <TableRowV2
                className=""
                key={index->string_of_int}
                onMouseEnter={_ => setShowVisible(_ => index)}
                onMouseLeave={_ => setShowVisible(_ => (-1))}>
                {getTableRow(rData, columns, index == showVisible)}
              </TableRowV2>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
