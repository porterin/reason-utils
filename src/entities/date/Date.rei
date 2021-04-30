type t;
let make: (~value: string, ~format: string) => t;
let toString: (~format: string, ~date: t) => string;