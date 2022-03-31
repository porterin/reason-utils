open MomentTz;

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

type scaleUnit = [
  | `year
  | `quarter
  | `month
  | `week
  | `isoWeek
  | `day
  | `hour
  | `minute
  | `second
  | `millisecond
];

let setTz: string => unit = [%bs.raw
  {|
      function (tz) {
        MomentTimezone.tz.setDefault(tz);
      }
  |}
];

let now = () => momentNow();

let toFloat = moment => moment->Moment.valueOf;

let fromTimestampMs = (value: float): Moment.t => value->momentWithTimestampMS;

let formatFromFloat = (~format: string, ~timestamp: float) =>
  Moment.format(format, momentWithTimestampMS(timestamp));

let formatFromJsDate = (~format: string, ~date: Js.Date.t) =>
  Moment.format(format, momentWithDate(date));

let fromJsDate = (date: Js.Date.t): Moment.t => date->momentWithDate;

let toJsDate = (date: Moment.t): Js.Date.t => date->Moment.toDate;

let fromString = (~date: string, ~format: string): Moment.t => momentWithFormat(date, format);

let isBefore = (~first_date: Moment.t, ~second_date: Moment.t) =>
  Moment.isBefore(first_date, second_date);

let isAfter = (~first_date: Moment.t, ~second_date: Moment.t) =>
  Moment.isAfter(first_date, second_date);

let toMomentTimeUnit = (t: TimeUnit.t): timeUnit => {
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

let toMomentScaleUnit = (t: ScaleUnit.t): scaleUnit => {
  switch (t) {
  | Year => `year
  | Quarter => `quarter
  | Month => `month
  | Week => `week
  | IsoWeek => `isoWeek
  | Day => `day
  | Hour => `hour
  | Minute => `minute
  | Second => `second
  | Millisecond => `millisecond
  };
};

let getDateTimeAfterElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t)
    : MomentTz.Moment.t => {
  let toDuration = duration(elapsed_time, toMomentTimeUnit(time_unit));
  Moment.add(~duration=toDuration, initial_date);
};

let getDateTimeBeforeElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t)
    : MomentTz.Moment.t => {
  let toDuration = duration(elapsed_time, toMomentTimeUnit(time_unit));
  Moment.subtract(~duration=toDuration, initial_date);
};

let startOf = (moment, scale: ScaleUnit.t) => {
  moment |> Moment.startOf(toMomentScaleUnit(scale));
};

let endOf = (moment, scale: ScaleUnit.t) => {
  moment |> Moment.endOf(toMomentScaleUnit(scale));
};
