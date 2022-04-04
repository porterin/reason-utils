[@decco]
type t;

let make: float => t;

let setTz: string => unit;

let now: unit => t;

let toString: (~value: t, ~format: string) => string;

let isBefore: (~first_date: t, ~second_date: t) => bool;

let isAfter: (~first_date: t, ~second_date: t) => bool;

let getDateTimeAfterElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => t;

let tomorrow: unit => t;

let getDateTimeBeforeElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => t;

let getPreviousDateByDays: (~day: int) => t;

/* To Deprecate */
let utcToIst: (~value: t) => t;

let toFloat: t => float;

let toJsDate: t => Js.Date.t;

let fromJsDate: Js.Date.t => t;

let startOf: (~ts: t, ~scale_unit: ScaleUnit.t) => t;

let endOf: (~ts: t, ~scale_unit: ScaleUnit.t) => t;
