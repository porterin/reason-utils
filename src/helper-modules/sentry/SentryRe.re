type static;

[@bs.module "./Sentry.js"] external init: (string, array(Js_re.t)) => unit = "init";
[@bs.module "./Sentry.js"] external captureException: Js.Exn.t => static = "captureException";
[@bs.module "./Sentry.js"]
external capturePromiseError: Js.Promise.error => static = "capturePromiseError";
[@bs.module "./Sentry.js"] external captureMessage: string => string = "captureMessage";
[@bs.module "./Sentry.js"] external setTag: (string, string) => unit = "setTag";

let initSentry =
    (~environment: Environment.t, ~dsn: string, ~suppressErrors: array(Js_re.t)=[||], ()) => {
  switch (environment) {
  | Production => init(dsn, suppressErrors)
  | _ => ()
  };
};
