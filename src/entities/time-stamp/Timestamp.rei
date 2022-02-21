[@decco]
type t;

let make: float => t;

let now: unit => t;

let toString: (~value: t, ~format: string) => string;

let utcToIst: (~value: t) => t;

let toFloat: t => float;

let toStringWithTz: (~ts: t, ~offset: float, ~format: string) => string;
