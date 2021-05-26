type t;

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

let make: (~value: string, ~format: string) => t;
let toString: (~format: string, ~date: t) => string;

let now: unit => t;

let isBefore: (~d: t, ~referenceDate: t) => bool;

let isAfter: (~d: t, ~referenceDate: t) => bool;

let getDateTimeAfterElapsedTime: (float, timeUnit, t) => t;

let tomorrow: unit => t;

let fromTimeStamp: int => t;

let toTimeStamp: t => int;
