/* Milliseconds */
type t = float;

let make = (v: float): t => v;

let now = (): t => {
  MomentUtils.now()->MomentUtils.toFloat;
};

let toString = (~value: t, ~format): string => {
  MomentUtils.formatFromFloat(~format, ~timestamp=value);
};
