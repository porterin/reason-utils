let isFileExtensionValid: (~fileType: string) => Belt.Result.t(string, string);

let getContentRows: CsvFileParser.Results.t => Belt.Result.t(array(array(string)), string);

let prepareCsvRows: CsvFileParser.Results.t => Belt.Result.t(list(CsvRow.t), string);

let getRowsWithoutHeader: array(array(string)) => array(array(string));

let getHeaderRow: array(array(string)) => Belt.Result.t(array(string), string);
