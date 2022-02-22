type t;

let toJsDate: t => Js.Date.t;

let fromJsDate: Js.Date.t => t;

let make: (~value: string, ~format: string) => t;

let toString: (~format: string, ~date: t) => string;

let now: unit => t;

let isBefore: (~first_date: t, ~second_date: t) => bool;

let isAfter: (~first_date: t, ~second_date: t) => bool;

let getDateTimeAfterElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => t;

let tomorrow: unit => t;

let getDateTimeBeforeElapsedTime:
  (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => t;

let getPreviousDateByDays: (~day: int) => t;
