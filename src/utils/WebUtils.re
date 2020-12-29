let debounce = (fn: 'a => unit, time) => {
  let last = ref(None);
  v => {
    switch (last^) {
    | Some(t) => Js.Global.clearTimeout(t)
    | None => ()
    };
    last := Some(Js.Global.setTimeout(() => fn(v), time));
  };
};
