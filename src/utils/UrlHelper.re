module QueryParamsConstructor = {
    let rec fold = (~lst: list(string), ~value: string="", ()): string => {
      switch (lst) {
      | [] => value
      | [head] => value ++ head
      | [head, ...tail] => head ++ "&" ++ fold(~lst=tail, ~value, ())
      };
    };
    let create = (urlParams: Js.Dict.t(string)): option(string) => {
      let keys = Js.Dict.keys(urlParams) |> Array.to_list;
      List.length(keys) > 0
        ? keys
          |> List.map(key => {
              key ++ "=" ++ urlParams->Js.Dict.get(key)->Belt.Option.getWithDefault("")
            })
          |> (paramsList => fold(~lst=paramsList, ()) |> (queryParam => Some(queryParam)))
        : None;
    };
  }