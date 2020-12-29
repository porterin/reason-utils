let getNestedJSON = (key: string, json: Js.Json.t): Js.Json.t => {
  Js.Json.decodeObject(json)->Belt.Option.getExn->Js.Dict.get(key)->Belt.Option.getExn;
};
