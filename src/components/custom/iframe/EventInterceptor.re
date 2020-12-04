/* https://davidwalsh.name/window-iframe */
let eventInterpretor = (e: MessageEvent.t, cb: _ => unit) => {
  let payload = MessageEvent.getData(e);
  if (payload##messageType == "internal redirect") {
    Js.log2("Payload from event: ", payload);
    cb(_ => payload);
  };
};

let useIframeEvents = () => {
  let initialState: MessageEvent.messageEventPayload = Js.Obj.empty();
  let (state, setState) = React.useState(_ => initialState);
  React.useEffect0(() => {
    let document = Webapi.Dom.Window.asEventTarget(Webapi.Dom.window);
    Webapi.Dom.EventTarget.addEventListener(
      "message",
      e => eventInterpretor(e, setState),
      document,
    );
    Some(
      () =>
        Webapi.Dom.EventTarget.removeEventListener(
          "message",
          e => eventInterpretor(e, setState),
          document,
        ),
    );
  });
  state;
};
