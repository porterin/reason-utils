/* type timeUnit; */

let setTz: string => unit;

let getTz: unit => string;

let now: unit => MomentTzTestBindings.Moment.t;

let toFloat: MomentTzTestBindings.Moment.t => float;

let formatFromJsDate: (~format: string, ~date: Js.Date.t) => string;

let formatFromFloat: (~format: string, ~timestamp: float) => string;

let fromTimestampMs: float => MomentTzTestBindings.Moment.t;

let fromJsDate: Js.Date.t => MomentTzTestBindings.Moment.t;

let toJsDate: MomentTzTestBindings.Moment.t => Js.Date.t;

let fromString: (~date: string, ~format: string) => MomentTzTestBindings.Moment.t;

let isBefore:
  (~first_date: MomentTzTestBindings.Moment.t, ~second_date: MomentTzTestBindings.Moment.t) => bool;

let isAfter:
  (~first_date: MomentTzTestBindings.Moment.t, ~second_date: MomentTzTestBindings.Moment.t) => bool;

let getDateTimeAfterElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTzTestBindings.Moment.t) =>
  MomentTzTestBindings.Moment.t;

let getDateTimeBeforeElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: MomentTzTestBindings.Moment.t) =>
  MomentTzTestBindings.Moment.t;

let startOf: (MomentTzTestBindings.Moment.t, ScaleUnit.t) => MomentTzTestBindings.Moment.t;

let endOf: (MomentTzTestBindings.Moment.t, ScaleUnit.t) => MomentTzTestBindings.Moment.t;
