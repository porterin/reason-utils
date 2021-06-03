open MomentRe;

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

let now = () => momentNow();

let toFloat = moment => moment->Moment.valueOf;

let formatFromJsDate = (~format: string, ~date: Js.Date.t) =>
  Moment.format(format, momentWithDate(date));

let formatFromFloat = (~format: string, ~timestamp: float) =>
  Moment.format(format, momentWithTimestampMS(timestamp));

let fromTimestmapMs = (value: float): Moment.t => value->momentWithTimestampMS;

let fromJsDate = (date: Js.Date.t): Moment.t => date->momentWithDate;

let toJsDate = (date: Moment.t): Js.Date.t => date->Moment.toDate;

let fromString = (~date: string, ~format: string): Moment.t => momentWithFormat(date, format);

let isBefore = (~first_date: Moment.t, ~second_date: Moment.t) =>
  Moment.isBefore(first_date, second_date);

let isAfter = (~first_date: Moment.t, ~second_date: Moment.t) =>
  Moment.isAfter(first_date, second_date);

let fromJsTimeUnit = (t: TimeUnit.t): timeUnit => {
  switch (t) {
  | Years => `years
  | Quarters => `quarters
  | Months => `months
  | Weeks => `weeks
  | Days => `days
  | Hours => `hours
  | Minutes => `minutes
  | Seconds => `seconds
  | Milliseconds => `milliseconds
  };
};

let getDateTimeAfterElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentRe.Moment.t)
    : MomentRe.Moment.t => {
  let toDuration = duration(elapsed_time, fromJsTimeUnit(time_unit));
  Moment.add(~duration=toDuration, initial_date);
};
