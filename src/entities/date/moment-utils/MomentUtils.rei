type timeUnit;

let now: unit => MomentRe.Moment.t;

let toFloat: MomentRe.Moment.t => float;

let formatFromJsDate: (~format: string, ~date: Js.Date.t) => string;

let formatFromFloat: (~format: string, ~timestamp: float) => string;

let fromTimestampMs: float => MomentRe.Moment.t;

let fromJsDate: Js.Date.t => MomentRe.Moment.t;

let toJsDate: MomentRe.Moment.t => Js.Date.t;

let fromString: (~date: string, ~format: string) => MomentRe.Moment.t;

let isBefore: (~first_date: MomentRe.Moment.t, ~second_date: MomentRe.Moment.t) => bool;

let isAfter: (~first_date: MomentRe.Moment.t, ~second_date: MomentRe.Moment.t) => bool;

let getDateTimeAfterElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentRe.Moment.t) =>
  MomentRe.Moment.t;

let diffDates:
  (
    ~start_date: Js.Date.t,
    ~end_date: Js.Date.t,
    ~time_unit: TimeUnit.t
  ) => float