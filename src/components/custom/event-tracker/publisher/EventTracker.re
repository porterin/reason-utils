let getGaEventPayload =
    (payload: CommonTrackingPayload.event): GaTrackingPayload.event => {
  category: payload.category,
  action: payload.action,
  value: payload.value,
  label:
    Json.Decode.(
      Belt.Option.getWithDefault(payload.extra_params, Js.Json.null)
      |> optional(field("label", string))
    ),
  nonInteraction:
    Json.Decode.(
      Belt.Option.getWithDefault(payload.extra_params, Js.Json.null)
      |> optional(field("nonInteraction", bool))
    ),
};
let getGaPageviewPayload =
    (payload: CommonTrackingPayload.pageview): GaTrackingPayload.pageview => {
  path: payload.path,
  title: Belt.Option.getWithDefault(payload.title, "N/A"),
};
let publishEvent = (payload: CommonTrackingPayload.event) => {
  payload->getGaEventPayload->GaPublisher.publishGaEvent;
};

let publishPageview = (payload: CommonTrackingPayload.pageview) => {
  payload->getGaPageviewPayload->GaPublisher.publishGaPageview;
};
