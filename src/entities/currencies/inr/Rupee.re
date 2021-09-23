type t = float;

let toRupee = (a: float): t => a->Js.Float.toFixedWithPrecision(~digits=2)->Js.Float.fromString;

let fromRupee = (a: t): float => a;

/* Rupee wihout Paisa */
let toStrictRupee = (a: t): int => a->int_of_float;

let fromStrictRupee = (a: int): t => a->float_of_int;

//Helpers
let fromOptRupee = (a: option(t)): option(float) =>
  a->Belt.Option.mapWithDefault(None, b => Some(b));

let add = (a, b): t => (a->fromRupee +. b->fromRupee)->toRupee;

let subtract = (a, b): t => (a->fromRupee -. b->fromRupee)->toRupee;

//View
let toCurrencyString = (a: t): string => {
  let prefix = a < 0.0 ? "-" : "";
  a->Js.Math.abs_float->Js.Float.toString
  |> Js.String.replaceByRe([%re "/\B(?=(\d{3})+(?!\d))/g"], ",")
  |> (value => prefix ++ {j| ₹|j} ++ value);
};

let toRoundedString = (a: t): string => {
  let prefix = a < 0.0 ? "-" : "";
  a->Js.Math.abs_float->Js.Float.toFixedWithPrecision(~digits=0)
  |> Js.String.replaceByRe([%re "/\B(?=(\d{3})+(?!\d))/g"], ",")
  |> (value => prefix ++ {j| ₹|j} ++ value);
};

let toTwoDigitPrecisionString = (a: t): string => {
  let prefix = a < 0.0 ? "-" : "";
  a->Js.Math.abs_float->Js.Float.toFixedWithPrecision(~digits=2)
  |> Js.String.replaceByRe([%re "/\B(?=(\d{3})+(?!\d))/g"], ",")
  |> (value => prefix ++ {j| ₹|j} ++ value);
};

let toString = (a: t): string => a->Js.Float.toString;

let fromString = (a: string): t =>
  a->Js.Float.fromString->Js.Float.toFixedWithPrecision(~digits=2)->Js.Float.fromString;
