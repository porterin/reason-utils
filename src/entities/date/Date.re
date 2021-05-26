type t = Js.Date.t;
type timeUnit = [
  | `years
  | `quarters
  | `months
  | `weeks
  | `days
  | `hours
  | `minutes
  | `seconds
  | `milliseconds
];
open MomentRe;

let make = (~value: string, ~format: string) => {
  MomentUtils.toDate(~value, ~format);
};

let toString = (~format: string, ~date: t) => {
  MomentUtils.toString(~format, ~date);
};

let now = (): t => {
  Js.Date.fromFloat(Js.Date.now());
};

let isBefore = (~d: t, ~referenceDate: t) => {
  Moment.isBefore(momentWithDate(d), momentWithDate(referenceDate));
};

let isAfter = (~d: t, ~referenceDate: t) => {
  Moment.isAfter(momentWithDate(d), momentWithDate(referenceDate));
};

let getDateTimeAfterElapsedTime = (elapsedTime: float, timeUnit: timeUnit, initialDate: t) => {
  let toDuration = duration(elapsedTime, timeUnit);
  let toMoment = Moment.add(~duration=toDuration, momentWithDate(initialDate));
  Moment.toDate(toMoment);
};

let tomorrow = () => {
  getDateTimeAfterElapsedTime(float_of_int(1), `days, Js.Date.fromFloat(Js.Date.now()));
};

let fromTimeStamp = (timestamp: int) => {
  Moment.toDate(momentWithUnix(timestamp));
};

let toTimeStamp = (date: t) => {
  Moment.toUnix(momentWithDate(date));
};
