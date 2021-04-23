type t = Js.Date.t

let make = (~value: string, ~format: string) => {
  MomentUtils.toDate(~value, ~format);
};

let toString = (~format: string, ~date: t) => {
  MomentUtils.toString(~format, ~date);
};