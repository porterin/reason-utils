let validateCsvResult:
  (CsvFileParser.Results.t, CsvValidationSchema.t, CsvRowResult.t => Belt.Result.t('a, string)) =>
  Belt.Result.t(list(Belt.Result.t('a, string)), string);
