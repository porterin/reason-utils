let getTableRow = (rowData: 't, columns: list(TableSchema.t('a))) => {
  columns
  |> List.mapi((key, columnHeader: TableSchema.t('a)) =>
       <TableCellComponent key={key->string_of_int} cell={columnHeader.accessor(rowData)} />
     )
  |> ReasonReactUtils.listToReactArray;
};

let getRows = (rowsData: GroupTableSchema.t('a), columns: list(TableSchema.t('a))) => {
  rowsData.rows
  |> List.mapi((key, rData) =>
       <TableRow key={key->string_of_int} className=""> {getTableRow(rData, columns)} </TableRow>
     )
  |> ReasonReactUtils.listToReactArray;
};

module TableHeader = {
  //added one empty cell in header row
  let getColumnHeaders = (~columns: list(TableSchema.t('a))): ReasonReact.reactElement => {
    columns
    |> List.mapi((key, columnHeader: TableSchema.t('a)) =>
         switch (columnHeader.column) {
         | Text(text) =>
           <MaterialUi.TableCell key={key->string_of_int}>
             {React.string(text)}
           </MaterialUi.TableCell>
         | Custom(renderFn) =>
           <MaterialUi.TableCell key={key->string_of_int}> {renderFn()} </MaterialUi.TableCell>
         }
       )
    |> ReasonReactUtils.listToReactArray;
  };

  let buildTableHeader = (~className: string, ~columns: list(TableSchema.t('a))) => {
    <MaterialUi.TableHead>
      <TableRow className> <MaterialUi.TableCell /> {getColumnHeaders(~columns)} </TableRow>
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
      ~stickyHeader: bool=false,
      ~className: string="",
      ~row_class_name: string="",
      ~accordion_row_class_name: string="",
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
    <Table className={"table " ++ className} stickyHeader>
      <TableHeader className={"table-header" ++ header_class_name} columns />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((key, (rData, collapsing_cell_data)) =>
              <>
                <TableRowV2
                  className=row_class_name
                  key={key->string_of_int}
                  onClick={_ => toggleFaqDisplay(key)}>
                  <TableCellComponent
                    cell={
                      Custom(
                        _ =>
                          <div
                            className="accordion-row-button" onClick={_ => toggleFaqDisplay(key)}>
                            {showRow != key
                               ? <Icon.KeyboardArrowDownIconIcon />
                               : <Icon.KeyboardArrowUpIconIcon className="active" />}
                          </div>,
                      )
                    }
                    colSpan=1
                  />
                  {getTableRow(rData, columns)}
                </TableRowV2>
                {showRow == key
                   ? <TableRow
                       className={
                         accordion_row_class_name
                         ++ {
                           showRow == key ? "__active" : "";
                         }
                       }
                       key={key->string_of_int ++ "a"}>
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
