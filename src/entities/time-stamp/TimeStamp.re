/* Milliseconds */
type t = float;

open MomentRe;

let now = (): t => {
  MomentRe.momentNow()->MomentRe.Moment.valueOf;
};

let toString = (~value: t, ~format): string => {
  Moment.format(format, momentWithTimestampMS(value));
};
