[@bs.val] [@bs.scope "window"] external redirect: (string, string) => unit = "open";
[@bs.val] [@bs.scope ("window", "history")] external invokeBack: unit => unit = "back";
[@bs.val] [@bs.scope "window"] external scrollTo: (int, int) => unit = "scrollTo";
[@bs.val] [@bs.scope "window"] external encodeURI: string => string = "encodeURI";
[@bs.val] [@bs.scope "window"] external decodeURI: string => string = "decodeURI";
[@bs.val] [@bs.scope "window"]
external encodeURIComponent: string => string = "encodeURIComponent";
[@bs.val] [@bs.scope "window"]
external decodeURIComponent: string => string = "decodeURIComponent";
[@bs.val] [@bs.scope "document"] external visibilityState: string = "visibilityState";
[@bs.get] external window: unit => Dom.window = "window";
[@bs.get] external parent: Dom.window => Dom.window = "parent";
[@bs.get] external location: Dom.window => Dom.location = "location";
[@bs.get] external host: Dom.location => string = "host";
[@bs.get] external hostname: Dom.element => string = "hostname";
[@bs.get] external pathname: Dom.element => string = "pathname";
[@bs.get] external search: Dom.element => string = "search";
[@bs.get] external port: Dom.element => string = "port";
[@bs.val] [@bs.scope ("window", "location")] external locationOrigin: string = "origin";
[@bs.val] [@bs.scope ("window", "location")] external currentUrl: string = "href";

[@bs.val] [@bs.scope "window"] external open_: string => unit = "open";

[@bs.val] [@bs.scope "document"] external cookie: string = "cookie";

[@bs.val] [@scope ("window", "navigator")] external userAgent: string = "userAgent"
[@bs.val] [@scope ("window", "navigator")] external standalone: Js.undefined('a) = "standalone"



[@bs.deriving abstract]
type naivgatorShareOptions = {
  url: option(string),
  text: string,
  title: string,
  [@bs.optional]
  files: array(FileRe.t),
};

[@bs.module "./navigator.js"]
external navigatorShare: naivgatorShareOptions => Js.Promise.t(unit) = "share";

[@bs.module "./navigator.js"] external canShare: unit => bool = "canShare";

[@bs.val] [@bs.scope "window"] external openInSameTab: (string, string) => unit = "open";
[@bs.module "./navigator.js"] external copyToClipboard: string => unit = "copyToClipboard";
