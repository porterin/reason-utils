let getColumnHeaders = (~columns: list('a), ~buildHeaderCell): array(ReasonReact.reactElement) => {
  columns
  |> List.mapi((index, columnHeader) =>  buildHeaderCell(~columnHeader, ~index))
  |> Array.of_list;
};

let buildTableHeader = (~className: string, ~columns: list('a), ~buildHeaderCell) => {
  <MaterialUi.TableHead>
    <TableRow className> {getColumnHeaders(~columns, ~buildHeaderCell)} </TableRow>
  </MaterialUi.TableHead>;
};

[@react.component]
let make = (~className: string, ~columns: list('a), ~buildHeaderCell) =>
  buildTableHeader(~className, ~columns, ~buildHeaderCell);
