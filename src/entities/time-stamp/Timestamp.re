/* Milliseconds */
[@decco]
type t = float;

let make = (v: float): t => v;

let now = (): t => {
  MomentUtils.now()->MomentUtils.toFloat;
};

let toString = (~value: t, ~format): string => {
  MomentUtils.formatFromFloat(~format, ~timestamp=value);
};

let utcToIst = (~value: t): t => {
  value +. 19800000.0;
};

let toFloat = (timestamp: t): float => {
  timestamp;
};

let toStringWithTz = (~ts: t, ~offset: float, ~format: string) => {
  let date = Js.Date.fromFloat(ts);
  let utc = Js.Date.getTime(date) +. Js.Date.getTimezoneOffset(date) *. 60000.0;
  let nd = Js.Date.fromFloat(utc +. 3600000.0 *. offset);
  MomentRe.momentWithDate(nd) |> MomentRe.Moment.format(format);
};
