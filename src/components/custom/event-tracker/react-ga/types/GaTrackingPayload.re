type event = {
  category: string,
  action: string,
  label: option(string),
  value: option(int),
  nonInteraction: option(bool),
};

type pageview = {
  path: string,
  title: string,
};
