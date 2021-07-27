type t;

let toRupee: float => t;

let fromRupee: t => float;

/* Rupee wihout Paisa */
let toStrictRupee: t => int;

let fromStrictRupee: int => t;

//Helpers
let fromOptRupee: option(t) => option(float);

let add: (t, t) => t;

let subtract: (t, t) => t;

//View
let toString: t => string;

let toCurrencyString: t => string;

let fromString: string => t;
