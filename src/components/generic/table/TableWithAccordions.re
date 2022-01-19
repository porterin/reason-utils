let getRows = (rowsData: GroupTableSchema.t('a), columns: list(TableSchema.t('a))) => {
  rowsData.rows
  |> List.mapi((key, rowData) =>
       <TableRow key={key->string_of_int} className="">
         {TableRowBuilder.execute(rowData, columns)}
       </TableRow>
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

  let getEmptyHeaderCell = () => {
    <MaterialUi.TableCell />;
  };

  let buildTableHeader = (~className: string, ~columns: list(TableSchema.t('a))) => {
    <MaterialUi.TableHead>
      <TableRow className> {getEmptyHeaderCell()} {getColumnHeaders(~columns)} </TableRow>
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
      ~rows: list(('a, TableCell.t)),
      ~is_sticky_header: bool=false,
      ~class_name: string="",
      ~row_class_name: string="",
      ~collapsible_row_class_name: string="",
      ~header_class_name: string="",
    ) => {
  let (openRowIndex, setOpenRowIndex) = React.useState(_ => (-1));

  let toggleRow = (index: int) =>
    if (openRowIndex == index) {
      setOpenRowIndex(_ => (-1));
    } else {
      setOpenRowIndex(_ => index);
    };

  let shouldToggle = (index: int): bool => {
    openRowIndex == index;
  };

  <>
    <Table className={"table " ++ class_name} is_sticky_header>
      <TableHeader className={"table-header" ++ header_class_name} columns />
      <TableBody className="table-body">
        {rows
         |> List.mapi((key, (rowData, collapsible_row_data)) =>
              <>
                <TableRowWithMouseCb
                  className=row_class_name key={key->string_of_int} onClick={_ => toggleRow(key)}>
                  <TableCellComponent
                    cell={
                      Custom(
                        _ =>
                          <div className="accordion-row-button" onClick={_ => toggleRow(key)}>
                            {openRowIndex != key
                               ? <Icon.KeyboardArrowDownIconIcon />
                               : <Icon.KeyboardArrowUpIconIcon className="active" />}
                          </div>,
                      )
                    }
                    colSpan=1
                  />
                  {TableRowBuilder.execute(rowData, columns)}
                </TableRowWithMouseCb>
                {shouldToggle(key)
                   ? <TableRow
                       className={
                         collapsible_row_class_name
                         ++ {
                           shouldToggle(key) ? "__active" : "";
                         }
                       }
                       key={key->string_of_int ++ "a"}>
                       <TableCellComponent
                         cell=collapsible_row_data
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
