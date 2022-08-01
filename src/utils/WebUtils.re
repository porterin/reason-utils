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

let androidRegex = "(android.*wv)"; // Work for Android Lollipop and above versions 
let isWebView = ():bool =>{ 
  let userAgent = Js.String2.toLowerCase(JsBindings.userAgent); 
  userAgent->Js.String2.search(Js.Re.fromString(androidRegex))>=0
  }