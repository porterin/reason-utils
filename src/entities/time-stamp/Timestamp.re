/* Milliseconds */
[@decco]
type t = float;

let make = (v: float): t => v;

let setTz = (tz: string) => {
  MomentUtils.setTz(tz);
};

let now = (): t => {
  MomentUtils.now()->MomentUtils.toFloat;
};

let toString = (~value: t, ~format): string => {
  MomentUtils.formatFromFloat(~format, ~timestamp=value);
};

/* To Deprecate */
let utcToIst = (~value: t): t => {
  value +. 19800000.0;
};

let toFloat = (timestamp: t): float => {
  timestamp;
};

let toJsDate = (timestamp: t): Js.Date.t => {
  MomentUtils.fromTimestampMs(timestamp)->MomentUtils.toJsDate;
};

let fromJsDate = (date: Js.Date.t): t => {
  MomentUtils.fromJsDate(date)->MomentUtils.toFloat;
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

let getDateTimeAfterElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t): t => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time,
    ~time_unit,
    ~initial_date=MomentUtils.fromTimestampMs(initial_date),
  )
  ->MomentUtils.toFloat;
};

let tomorrow = (): t => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time=float_of_int(1),
    ~time_unit=Days,
    ~initial_date=MomentUtils.now(),
  )
  ->MomentUtils.toFloat;
};

let getDateTimeBeforeElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t): t => {
  MomentUtils.getDateTimeBeforeElapsedTime(
    ~elapsed_time,
    ~time_unit,
    ~initial_date=MomentUtils.fromTimestampMs(initial_date),
  )
  ->MomentUtils.toFloat;
};

let getPreviousDateByDays = (~day: int): t => {
  getDateTimeBeforeElapsedTime(
    ~elapsed_time=float_of_int(day),
    ~time_unit=Days,
    ~initial_date=now(),
  );
};

let startOf = (~ts: t, ~scale_unit: ScaleUnit.t): t => {
  ts->MomentUtils.fromTimestampMs->MomentUtils.startOf(scale_unit)->MomentUtils.toFloat;
};

let endOf = (~ts: t, ~scale_unit: ScaleUnit.t): t => {
  ts->MomentUtils.fromTimestampMs->MomentUtils.endOf(scale_unit)->MomentUtils.toFloat;
};
