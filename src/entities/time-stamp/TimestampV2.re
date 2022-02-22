/* Milliseconds */
[@decco]
type t = float;

let make = (v: float): t => v;

let toFloat = (timestamp: t): float => {
  timestamp;
};

let utc = (): t => {
  MomentUtils.now()->MomentUtils.toFloat;
};

let toDate = (~ts: t, ~offset: float): Date.t => {
  let date = Js.Date.fromFloat(ts);
  let utc = Js.Date.getTime(date) +. Js.Date.getTimezoneOffset(date) *. 60000.0;
  Js.Date.fromFloat(utc +. 3600000.0 *. offset)->Date.fromJsDate;
};

let toString = (~ts: t, ~offset: float, ~format: string) => {
  let date = Js.Date.fromFloat(ts);
  let utc = Js.Date.getTime(date) +. Js.Date.getTimezoneOffset(date) *. 60000.0;
  let nd = Js.Date.fromFloat(utc +. 3600000.0 *. offset);
  MomentRe.momentWithDate(nd) |> MomentRe.Moment.format(format);
};

let isBefore = (~first_date: t, ~second_date: t) => {
  MomentUtils.isBefore(
    ~first_date=MomentUtils.fromTimestampMs(first_date),
    ~second_date=MomentUtils.fromTimestampMs(second_date),
  );
};

let isAfter = (~first_date: t, ~second_date: t) => {
  MomentUtils.isAfter(
    ~first_date=MomentUtils.fromTimestampMs(first_date),
    ~second_date=MomentUtils.fromTimestampMs(second_date),
  );
};
