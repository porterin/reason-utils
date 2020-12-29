type fileInput = FileInput.t;

module CsvParseError = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "type"]
    type_: string,
    code: string,
    message: string,
    row: int,
  };
};

module Meta = {
  [@bs.deriving abstract]
  type t = {
    delimiter: string,
    linebreak: string,
    aborted: bool,
    fields: array(string),
    truncated: bool,
  };
};

module Results = {
  [@bs.deriving abstract]
  type t = {
    data: array(array(string)),
    error: array(CsvParseError.t),
    meta: Meta.t,
  };
};

module ParseConfig = {
  [@bs.deriving abstract]
  type t = {complete: (Results.t, fileInput) => unit};
};

[@bs.val] [@bs.module "papaparse"] external parse: (fileInput, ParseConfig.t) => unit = "parse";

type onComplete = Results.t => unit;

let parseFile = (~fileInput: fileInput, ~onComplete: onComplete) => {
  let parseConfig: ParseConfig.t =
    ParseConfig.t(~complete=(result: Results.t, _fileInp) => {onComplete(result)});
  parse(fileInput, parseConfig);
};
