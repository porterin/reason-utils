type t;

let make: (float) => t;

let now : unit => t;

let toString: (~value: t, ~format: string) => string;
