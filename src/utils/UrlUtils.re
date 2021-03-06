let getURLParams = (searchStr: string): Js.Dict.t(string) => {
  let urlParams = Js.Dict.empty();
  Js.String.split("&", searchStr)
  |> Array.iter(param => {
       let params = Js.String.split("=", param);
       if (Array.length(params) >= 2) {
         Js.Dict.set(urlParams, params[0], params[1]);
       };
     });
  urlParams;
};

let createRequestURLfrmParams =
    (hostName: string, requestUrl: string, urlParams: Js.Dict.t(string)) => {
  switch (QueryParamsConstructor.create(urlParams)) {
  | Some(args) => hostName ++ requestUrl ++ "?" ++ args
  | None => hostName ++ requestUrl
  };
};

let getAnchorElement = (url: string) => {
  let document = Webapi.Dom.Window.document(Webapi.Dom.window);
  let elem = Webapi.Dom.Document.createElement("a", document);
  Webapi.Dom.Element.setAttribute("href", url, elem);
  elem;
};

let getHostName = (url: string) => {
  let elem = getAnchorElement(url);
  if (JsBindings.port(elem) == "") {
    JsBindings.hostname(elem);
  } else {
    String.concat(":", [JsBindings.hostname(elem), JsBindings.port(elem)]);
  };
};

let getPathSplitParts = (url: string): array(string) => {
  let location = Js.String.split("/", JsBindings.pathname(getAnchorElement(url)));
  Array.sub(location, 1, Array.length(location) - 1);
};

let getSearchParams = (url: string) => {
  Js.String.substr(~from=1, JsBindings.search(getAnchorElement(url)));
};

let getCurrentPageHost = () => {
  JsBindings.location(Webapi.Dom.window) |> JsBindings.host;
};
