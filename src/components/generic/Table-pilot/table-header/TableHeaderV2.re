let getColumnHeaders = (~columns: list(TableSchemaV2.t('a))): array(ReasonReact.reactElement) => {
  columns
  |> List.mapi((index, columnHeader: TableSchemaV2.t('a)) =>
       switch (columnHeader.column) {
       | Text(text) =>
         <MaterialUi.TableCell key={index->string_of_int}>
           {React.string(text)}
         </MaterialUi.TableCell>
       | Custom(renderFn) =>
         <MaterialUi.TableCell key={index->string_of_int}> {renderFn()} </MaterialUi.TableCell>
       }
     )
  |> Array.of_list;
};

let buildTableHeader = (~className: string, ~columns: list(TableSchemaV2.t('a))) => {
  <MaterialUi.TableHead>
    <TableRow className> {getColumnHeaders(~columns)} </TableRow>
  </MaterialUi.TableHead>;
};

[@react.component]
let make = (~className: string, ~columns: list(TableSchemaV2.t('a))) =>
  buildTableHeader(~className, ~columns);
