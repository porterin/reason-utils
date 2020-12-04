let getColumnHeaders = (~columns: list(TableSchema.t('a))): array(ReasonReact.reactElement) => {
  columns
    |> List.map((columnHeader: TableSchema.t('a)) =>
        switch (columnHeader.column) {
        | Text(text) =>
          <MaterialUi.TableCell>
            {React.string(text)}
          </MaterialUi.TableCell>
        | Custom(renderFn) => renderFn()
        }
      )
    |> Array.of_list

};

let buildTableHeader = (~className: string, ~columns: list(TableSchema.t('a))) => {
  <MaterialUi.TableHead>
    <TableRow className>
      {getColumnHeaders(~columns)}
    </TableRow>
  </MaterialUi.TableHead>
};

[@react.component]
let make = (~className: string, ~columns: list(TableSchema.t('a))) => buildTableHeader(~className, ~columns);
