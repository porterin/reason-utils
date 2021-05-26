/* Milliseconds */
type t = float;

let fromTimeStamp = (timestamp: t) => {
  MomentRe.Moment.toDate(MomentRe.momentWithTimestampMS(timestamp));
};
