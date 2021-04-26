let getGaEventPayload = (payload: CommonTrackingPayload.event): GaTrackingPayload.event => {
  category: payload.category,
  action: payload.action,
  value: payload.value,
  label: payload.label,
  nonInteraction: payload.nonInteraction,
};
let getGaPageviewPayload = (payload: CommonTrackingPayload.pageview): GaTrackingPayload.pageview => {
  path: payload.path,
  title: payload.title,
};
let publishEvent = (payload: CommonTrackingPayload.event) => {
  payload->getGaEventPayload->GaPublisher.publishGaEvent;
};

let publishPageview = (payload: CommonTrackingPayload.pageview) => {
  payload->getGaPageviewPayload->GaPublisher.publishGaPageview;
};
