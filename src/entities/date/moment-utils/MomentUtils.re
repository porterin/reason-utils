open MomentTz;

let setTz = tz => {
  MomentTz.setTz(tz);
};

let getTz = () => getTz();

let now = () => momentNow();

let toFloat = moment => moment->valueOf;

let fromTimestampMs = (value: float): Moment.t => value->momentWithTimestampMS;

let format = (value: Moment.t, format: string) => MomentTz.format(value, format);

let formatFromFloat = (~format: string, ~timestamp: float) =>
  MomentTz.format(momentWithTimestampMS(timestamp), format);

let formatFromJsDate = (~format: string, ~date: Js.Date.t) =>
  MomentTz.format(momentWithDate(date), format);

let fromJsDate = (date: Js.Date.t): Moment.t => date->momentWithDate;

let toJsDate = (date: Moment.t): Js.Date.t => date->MomentTz.toJsDate;

let fromString = (~date: string, ~format: string): Moment.t => momentWithFormat(date, format);

let isBefore = (~first_date: Moment.t, ~second_date: Moment.t) =>
  isBefore(first_date, second_date);

let isAfter = (~first_date: Moment.t, ~second_date: Moment.t) =>
  isAfter(first_date, second_date);

let toMomentTimeUnit = (t: TimeUnit.t): string => {
  switch (t) {
  | Years => "years"
  | Quarters => "quarters"
  | Months => "months"
  | Weeks => "weeks"
  | Days => "days"
  | Hours => "hours"
  | Minutes => "minutes"
  | Seconds => "seconds"
  | Milliseconds => "milliseconds"
  };
};

let toMomentScaleUnit = (t: ScaleUnit.t): string => {
  switch (t) {
  | Year => "year"
  | Quarter => "quarter"
  | Month => "month"
  | Week => "week"
  | IsoWeek => "isoWeek"
  | Day => "day"
  | Hour => "hour"
  | Minute => "minute"
  | Second => "second"
  | Millisecond => "millisecond"
  };
};

let getDateTimeAfterElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t)
    : MomentTz.Moment.t => {
  getDateTimeAfterElapsedTime(elapsed_time, toMomentTimeUnit(time_unit), initial_date);
};

let getDateTimeBeforeElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t)
    : MomentTz.Moment.t => {
  getDateTimeBeforeElapsedTime(elapsed_time, toMomentTimeUnit(time_unit), initial_date);
};

let startOf = (moment, scale: ScaleUnit.t) => {
  startOf(moment, toMomentScaleUnit(scale));
};

let endOf = (moment, scale: ScaleUnit.t) => {
  endOf(moment, toMomentScaleUnit(scale));
};

let setOtherZone = date => {
  setOtherZone(date, getTz());
};

let setLocalZone = date => {
  setLocalZone(date, getTz());
};
