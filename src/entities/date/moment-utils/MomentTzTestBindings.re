module Moment = {
  type t;
};

[@bs.module "./MomentTzTest"] external setTz: string => unit = "setTz";

[@bs.module "./MomentTzTest"] external momentNow: unit => Moment.t = "now";

[@bs.module "./MomentTzTest"]
external momentWithTimestampMS: float => Moment.t = "momentWithTimestampMS";

[@bs.module "./MomentTzTest"] external format: (Moment.t, string) => string = "format";
[@bs.module "./MomentTzTest"] external momentWithDate: Js.Date.t => Moment.t = "momentWithDate";
[@bs.module "./MomentTzTest"] external toJsDate: Moment.t => Js.Date.t = "toJsDate";
[@bs.module "./MomentTzTest"]
external momentWithFormat: (string, string) => Moment.t = "momentWithFormat";
[@bs.module "./MomentTzTest"] external isBefore: (Moment.t, Moment.t) => bool = "isBefore";
[@bs.module "./MomentTzTest"] external isAfter: (Moment.t, Moment.t) => bool = "isBefore";
[@bs.module "./MomentTzTest"]
external getDateTimeAfterElapsedTime: (float, string, Moment.t) => Moment.t =
  "getDateTimeAfterElapsedTime";
[@bs.module "./MomentTzTest"]
external getDateTimeBeforeElapsedTime: (float, string, Moment.t) => Moment.t =
  "getDateTimeBeforeElapsedTime";
[@bs.module "./MomentTzTest"] external startOf: (Moment.t, string) => Moment.t = "startOf";
[@bs.module "./MomentTzTest"] external endOf: (Moment.t, string) => Moment.t = "endOf";
[@bs.module "./MomentTzTest"] external valueOf: Moment.t => float = "valueOf";
[@bs.module "./MomentTzTest"] external getTz: unit => string = "getTz";
