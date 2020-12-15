let filterEmptyRows = (rows: array(array(string))) => {
  rows
  |> Array.to_list
  |> List.filter((rowItem: array(string)) => String.concat("", Array.to_list(rowItem)) != "")
  |> Array.of_list;
};

let getRowsWithoutHeader = (rows: array(array(string))) => {
  let rowLength = Array.length(rows);
  Array.sub(rows, 1, rowLength - 1);
};

let validateLength = (rows: array(array(string))) => {
  switch (rows |> filterEmptyRows |> Array.length) {
  | length when length > 1 => Belt.Result.Ok(rows)
  | _ => Belt.Result.Error("No entries present")
  };
};

let getHeaderRow = (rows: array(array(string))): Belt.Result.t(array(string), string) => {
  switch (rows |> filterEmptyRows |> Array.length) {
  | length when length > 0 =>
    Belt.Result.Ok(
      rows[0] |> Array.to_list |> List.filter(r => r |> String.trim != "") |> Array.of_list,
    )
  | _ => Belt.Result.Error("no content present")
  };
};

let isFileExtensionValid = (~fileType: string): Belt.Result.t(string, string) =>
  switch (fileType) {
  | "text/csv"
  | "application/vnd.ms-excel" => Belt.Result.Ok(fileType)
  | _ => Belt.Result.Error(fileType ++ " is not a csv file")
  };

let getContentRows =
    (result: CsvFileParser.Results.t): Belt.Result.t(array(array(string)), string) => {
  let rows = CsvFileParser.Results.dataGet(result);
  switch (validateLength(rows)) {
  | Belt.Result.Ok(rows) => Belt.Result.Ok(getRowsWithoutHeader(rows))
  | Belt.Result.Error(error) => Belt.Result.Error(error)
  };
};

let mapRowToHeaderLabel = (row: array(string), header: array(string)) => {
  let (_idx, rowMap) =
    row
    |> ArrayUtils.firstN(Array.length(header))
    |> Array.fold_left(
         ((index: int, rMap: CsvRow.t), value) => {
           (index + 1, ReMapUtils.StringMap.add(header[index], value, rMap))
         },
         (0, ReMapUtils.StringMap.empty),
       );
  rowMap;
};

let mapRowsToLabel = (headerRow: array(string), rows: array(array(string))) => {
  Belt.Result.Ok(
    rows
    |> Array.map((row: array(string)) => mapRowToHeaderLabel(row, headerRow))
    |> Array.to_list,
  );
};

let getRowsFromResultAndMap = (result: CsvFileParser.Results.t, headerRow: array(string)) => {
  Belt.Result.flatMap(getContentRows(result), mapRowsToLabel(headerRow));
};

let prepareCsvRows = (result: CsvFileParser.Results.t): Belt.Result.t(list(CsvRow.t), string) => {
  let rows = CsvFileParser.Results.dataGet(result);
  let headerRowResult = getHeaderRow(rows);
  Belt.Result.flatMap(headerRowResult, getRowsFromResultAndMap(result));
};
