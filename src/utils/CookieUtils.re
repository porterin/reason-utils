open OptionTypeUtils;
type cookie = {
  key: string,
  value: string,
};

let getCookies = (): list(cookie) => {
  let cookies = JsBindings.cookie;
  let cookiesLength = Js.String.length(cookies);
  let ca =
    switch (cookiesLength) {
    | 0 => []
    | _ =>
      cookies |> Js.String.replaceByRe([%re "/ /g"], "") |> Js.String.split(";") |> Array.to_list
    };
  ca
  |> List.map(a => {
       let cookie = a |> Js.String.splitByRe([%re "/=(.+)/g"]);
       switch (Array.length(cookie)) {
       | 0
       | 1 => {
         key: getEmptyStringFrmOptionalType(cookie[0]),
         value: "",
       }
       | _ => {
         key: getEmptyStringFrmOptionalType(cookie[0]),
         value: getEmptyStringFrmOptionalType(cookie[1]),
       }
       };
     });
};

let getCookie = (cookieName: string): Js.Json.t => {
  let cookies = getCookies();
  let cookie =
    cookies |> List.exists(a => a.key === cookieName)
      ? Some(List.find(a => a.key === cookieName, cookies)) : None;

  switch (cookie) {
  | None => Json.Encode.object_([])
  | Some(cookie) => Json.Encode.object_([(cookieName, Json.Encode.string(cookie.value))])
  };
};

let setCookie: string => unit = [%bs.raw {|
 function (cookie) {
  document.cookie=cookie
 }
|}];
