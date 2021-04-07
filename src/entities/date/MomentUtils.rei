type t
let toDate: (~format: string, ~value: string) => t;
let toString: (~format: string, ~date: t) => string;