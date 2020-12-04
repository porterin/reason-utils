let resolveResult = (result: Belt.Result.t('a, Decco.decodeError), path: string): 'a => {
  switch (result) {
  | Ok(parsedData) => parsedData
  | Error(error) =>
    ErrorUtils.raiseError(
      ~path,
      ~message=error.path ++ " " ++ error.message,
      ~value=Js.Json.stringify(error.value),
    )
  };
};

module DateUtils = {
  type t = Js.Date.t;
  let t_decode = json => {
    Decco.stringFromJson(json)->Belt.Result.map(Js.Date.fromString);
  };

  let t_encode = date => {
    DateTime.toString(~format="DD/MM/YYYY HH:mm:ss", date);
  };
};
