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


/* 
Below regex ork for Android Lollipop and above versions 
*/
let androidRegex = "(android.*wv)";

/*
Regex required to find web view for iOS devices
*/
let iOSDeviceRegex = "(iphone|ipod|ipad)";
let iOSBrowserRegex = "(safari)";

let isWebView = ():bool =>{ 
  let userAgent = Js.String2.toLowerCase(JsBindings.userAgent); 
  let isStandalone = Js.undefinedToOption(JsBindings.standalone)->Belt.Option.getWithDefault("false")->bool_of_string; 
  let isIosDevice = userAgent->Js.String2.search(Js.Re.fromString(iOSDeviceRegex))>=0
  let isSafari = userAgent->Js.String2.search(Js.Re.fromString(iOSBrowserRegex))>=0

  switch(isIosDevice){
    |true=> switch(isStandalone,isSafari){
      |(false,false)=>true
      |(_,_)=>false
    }
    |_=>userAgent->Js.String2.search(Js.Re.fromString(androidRegex))>=0
  }
}