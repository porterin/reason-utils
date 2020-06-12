let get_ga_label = (request: EvenTrackRequest.t) => {
  Belt.Option.flatMap(request.value, reqValue => switch reqValue {
    | Int(int_val) => Some(string_of_int(int_val))
    | String(str_val) => Some(str_val)
  })
};

let record_event = (request: EvenTrackRequest.t) : unit => {
  GoogleTagManager.record_event({
    action: request.action,
    category: request.page,
    label: get_ga_label(request)
  });
};
