let getPreviousState = (state: 'a) => {
  let ref = React.useRef(state);
  React.useEffect(() => {
    ref.current= state;
    None;
  });
  ref.current;
};

let useInterval = (callback: _ => unit, delay: int) => {
  let savedCallback = React.useRef(callback);
  React.useEffect1(
    () => {
      savedCallback.current = callback;
      None;
    },
    [|callback|],
  );
  React.useEffect1(
    () => {
      let tick = savedCallback.current;
      let id = Js.Global.setInterval(tick, delay);
      Some(() => Js.Global.clearInterval(id));
    },
    [|delay|],
  );
};
