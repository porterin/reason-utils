/* Milliseconds */
[@decco]
type t = float;

let make = (v: float): t => v;

let now = (): t => {
  MomentUtils.now()->MomentUtils.toFloat;
};

let toString = (~value: t, ~format): string => {
  MomentUtils.formatFromFloat(~format, ~timestamp=value);
};

let utcToIst = (~value: t): t => {
  value +. 19800000.0;
};

let toFloat = (timestamp: t): float => {
  timestamp;
};
