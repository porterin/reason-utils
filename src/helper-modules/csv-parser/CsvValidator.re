let validateRow = (row: CsvRow.t, schema: CsvValidationSchema.t): CsvRowResult.t => {
  schema
  |> ReMapUtils.StringMap.mapi((key: string, validationType: CsvValidationType.t) =>
       try(
         row
         |> ReMapUtils.StringMap.find(key)
         |> (
           cellValue => {
             switch (validationType) {
             | String => Belt.Result.Ok(CsvCell.String(cellValue))
             | Number =>
               try(
                 int_of_string(cellValue)
                 |> (_number => Belt.Result.Ok(CsvCell.Number(cellValue)))
               ) {
               | _ => Belt.Result.Error("invalid number")
               }
             | Mobile =>
               ValidationHelper.MobileNumber.isValid(cellValue)
                 ? Belt.Result.Ok(CsvCell.Mobile(cellValue))
                 : Belt.Result.Error("invalid mobile")
             | Msisdn =>
               ValidationHelper.Msisdn.isValid(cellValue)
                 ? Belt.Result.Ok(CsvCell.Msisdn(cellValue))
                 : Belt.Result.Error("invalid msisdn")
             };
           }
         )
       ) {
       | _ => Belt.Result.Error(key ++ " not found in row")
       }
     );
};

let validateCsvRowAndMap =
    (
      schema: CsvValidationSchema.t,
      entityMapper: CsvRowResult.t => Belt.Result.t('a, string),
      csvRowList,
    ) =>
  Belt.Result.Ok(
    csvRowList |> List.map(row => validateRow(row, schema)) |> List.map(entityMapper),
  );

let validateCsvResult =
    (
      result: CsvFileParser.Results.t,
      schema: CsvValidationSchema.t,
      entityMapper: CsvRowResult.t => Belt.Result.t('a, string),
    )
    : Belt.Result.t(list(Belt.Result.t('a, string)), string) => {
  CsvHelper.prepareCsvRows(result)
  ->Belt.Result.flatMap(validateCsvRowAndMap(schema, entityMapper));
};
