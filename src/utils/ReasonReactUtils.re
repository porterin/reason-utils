let listToReactArray = (a: list(ReasonReact.reactElement)) =>
  a |> Array.of_list |> ReasonReact.array;

let sliceList = (lst: list('a), ~start: int=0, end_: int): list('a) => {
  lst->Belt.List.keepWithIndex((_: 'a, idx: int) => idx < end_ && idx >= start);
};

let optionIntToString = (a: option(int)): option(string) => {
  switch (a) {
  | None => None
  | Some(value) => Some(string_of_int(value))
  };
};

let optionBoolToString = (a: option(bool)): option(string) => {
  switch (a) {
  | None => None
  | Some(value) => Some(string_of_bool(value))
  };
};

let optionFloatToString = (a: option(float)): option(string) => {
  switch (a) {
  | None => None
  | Some(value) => Some(Js.Float.toString(value))
  };
};

let optionStringToReactText = (a: option(string)): CommonTypes.viewText => {
  switch (a) {
  | None => NoText
  | Some(value) => Text(value)
  };
};

let convertBoolToViewString = (a: bool): string => {
  a |> string_of_bool |> String.uppercase_ascii;
};
