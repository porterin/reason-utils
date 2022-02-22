[@decco]
type t;

let make: float => t;

let toFloat: t => float;

let utc: unit => t;

let toString: (~value: t, ~offset: float, ~format: string) => string;

let toDate: (~ts: t, ~offset: float) => Date.t;

let isBefore: (~first_date: t, ~second_date: t) => bool;

let isAfter: (~first_date: t, ~second_date: t) => bool;
