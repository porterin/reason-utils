let publishGaEvent = (payload: GaTrackingPayload.event) => {
  ReactGaBindings.event(payload);
};

let publishGaPageview = (payload: GaTrackingPayload.pageview) => {
  ReactGaBindings.pageview(payload.path, payload.title);
};
