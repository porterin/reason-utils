type static;

[@bs.module "./Sentry.js"] external init: (string, string) => unit = "init";
[@bs.module "./Sentry.js"] external captureException: Js.Exn.t => static = "captureException";
[@bs.module "./Sentry.js"] external capturePromiseError: Js.Promise.error => static = "capturePromiseError";
[@bs.module "./Sentry.js"] external captureMessage: string => string = "captureMessage";

let initSentry = (~environment: string, ~dsn: string) => {
  init(environment, dsn)
}