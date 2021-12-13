type static;

[@bs.module "./Sentry.js"] external init: (string, array(Js_re.t)) => unit = "init";
[@bs.module "./Sentry.js"] external captureException: Js.Exn.t => static = "captureException";
[@bs.module "./Sentry.js"]
external capturePromiseError: Js.Promise.error => static = "capturePromiseError";
[@bs.module "./Sentry.js"] external captureMessage: string => string = "captureMessage";

let initSentry = (~environment: Environment.t, ~suppressErrors: array(Js_re.t)=[||], ~dsn: string) => {
  switch (environment) {
  | Production => init(dsn, suppressErrors)
  | _ => ()
  };
};
