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

module TableHeader = {
  //added one empty cell in header row
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
      <TableRow className>
        <MaterialUi.TableCell />
        {getColumnHeaders(~columns)}
      </TableRow>
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
      ~row_class_name: string="",
      ~header_class_name: string="",
    ) => {
  let (showRow, setShowRow) = React.useState(_ => (-1));

  let toggleFaqDisplay = (ind: int) =>
    if (showRow == ind) {
      setShowRow(_ => (-1));
    } else {
      setShowRow(_ => ind);
    };

  <>
    <Table className={"table " ++ className}>
      <TableHeader className={"table-header" ++ header_class_name} columns />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((key, (rData, collapsing_cell_data)) =>
              <>
                <TableRow className=row_class_name key={key->string_of_int}>
                  <TableCellComponent
                    cell={
                      Custom(
                        _ =>
                          <div onClick={_ => toggleFaqDisplay(key)}>
                            {showRow != key
                               ? <Icon.KeyboardArrowDownIconIcon />
                               : <Icon.KeyboardArrowUpIconIcon />}
                          </div>,
                      )
                    }
                    colSpan=1
                  />
                  {getTableRow(rData, columns)}
                </TableRow>
                {showRow == key
                   ? <TableRow className="">
                       <TableCellComponent
                         cell=collapsing_cell_data
                         colSpan={columns->List.length + 1}
                       />
                     </TableRow>
                   : React.null}
              </>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
