[@bs.val] [@bs.scope "window"] external gtag: (string, string, Js.Json.t) => unit = "gtag";
[@bs.val] [@bs.scope "window"] external gtagJs: (string, Js.Date.t) => unit = "gtag";
[@bs.val] [@bs.scope "window"] external gtagConfig: (string, string) => unit = "gtag";

let setup_google_tag_manager = (key: string) => {
  gtagJs("js", Js.Date.make());
  gtagConfig("config", key);
};

let record_event = (request: GoogleTagManagerEventRequest.t) => {
  let action = request.action;
  let payload =
    Json.Encode.object_([
      ("event_category", Json.Encode.string(request.category)),
      ("event_label", Json.Encode.nullable(Json.Encode.string, request.label)),
    ]);
  gtag("event", action, payload);
};
