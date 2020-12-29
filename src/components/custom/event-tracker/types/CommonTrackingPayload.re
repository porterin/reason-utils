type event = {
  category: string,
  action: string,
  value: option(int),
  extra_params: option(Js.Json.t),
};

type pageview = {
  path: string,
  title: option(string),
  extra_params: option(Js.Json.t),
};
