type window;

[@bs.val] external self: window = "self";

module MessageEvent = {
  type t;
  [@bs.get] external data: t => 'a = "data";
};

[@bs.set] external setWorkerOnMessage: (window, MessageEvent.t => unit) => unit = "onmessage";

[@bs.send] external postMessage: (WebWorker.t, 'a) => unit = "postMessage";

[@bs.set] external onMessage: (WebWorker.t, MessageEvent.t => unit) => unit = "onmessage";

[@bs.val] external postMessageFromWorker: 'a => unit = "postMessage";
