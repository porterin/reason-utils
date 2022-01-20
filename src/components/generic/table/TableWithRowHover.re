module Schema = {
  type columnAccessor('a) = 'a => TableCell.t;

  type t('a) = {
    column: TableColumn.t,
    accessor: columnAccessor('a),
    is_visible_only_on_hover: bool,
  };

  let make_props =
      (
        ~column: TableColumn.t,
        ~accessor: columnAccessor('a),
        ~is_visible_only_on_hover: bool=false,
        (),
      )
      : t('a) => {
    column,
    accessor,
    is_visible_only_on_hover,
  };
};
let getTableRow = (rowData: 't, columns: list(Schema.t('a)), showVisible) => {
  columns
  |> List.mapi((index, columnHeader: Schema.t('a)) =>
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
      ~columns: list(Schema.t('a)),
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
        buildHeaderCell={(~columnHeader: Schema.t('a), ~index) => {
          switch (columnHeader.column) {
          | Text(text) =>
            <MaterialUi.TableCell key={index->string_of_int}>
              {React.string(text)}
            </MaterialUi.TableCell>
          | Custom(renderFn) =>
            <MaterialUi.TableCell key={index->string_of_int}> {renderFn()} </MaterialUi.TableCell>
          }
        }}
      />
      <TableBody className="table-body">
        {rowData
         |> List.mapi((index, rData) =>
              <CustomTableRow
                className=""
                key={index->string_of_int}
                onMouseEnter={_ => setShowVisible(_ => index)}
                onMouseLeave={_ => setShowVisible(_ => (-1))}>
                {getTableRow(rData, columns, index == showVisible)}
              </CustomTableRow>
            )
         |> ReasonReactUtils.listToReactArray}
      </TableBody>
    </Table>
  </>;
};
