type t = Dom.event;
type messageEventPayload = {
  .
  "path": string,
  "title": option(string),
  "messageType": string,
};
include Webapi__Dom__Event.Impl({
  type nonrec t = t;
});

[@bs.new] external make: string => t = "MessageEvent";
[@bs.new]
external makeWithOptions: (string, Js.t({..})) => t = "MessageEvent";

[@bs.get] external getData: t => messageEventPayload = "data";
