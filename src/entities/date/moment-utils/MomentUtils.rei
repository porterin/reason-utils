type timeUnit;

let setTz: string => unit;

let now: unit => MomentTz.Moment.t;

let toFloat: MomentTz.Moment.t => float;

let formatFromJsDate: (~format: string, ~date: Js.Date.t) => string;

let formatFromFloat: (~format: string, ~timestamp: float) => string;

let fromTimestampMs: float => MomentTz.Moment.t;

let fromJsDate: Js.Date.t => MomentTz.Moment.t;

let toJsDate: MomentTz.Moment.t => Js.Date.t;

let fromString: (~date: string, ~format: string) => MomentTz.Moment.t;

let isBefore: (~first_date: MomentTz.Moment.t, ~second_date: MomentTz.Moment.t) => bool;

let isAfter: (~first_date: MomentTz.Moment.t, ~second_date: MomentTz.Moment.t) => bool;

let getDateTimeAfterElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t) =>
  MomentTz.Moment.t;

let getDateTimeBeforeElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTz.Moment.t) =>
  MomentTz.Moment.t;
