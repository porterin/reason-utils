type static;

[@bs.module "./Sentry.js"] external init: string => unit = "init";
[@bs.module "./Sentry.js"] external captureException: Js.Exn.t => static = "captureException";
[@bs.module "./Sentry.js"]
external capturePromiseError: Js.Promise.error => static = "capturePromiseError";
[@bs.module "./Sentry.js"] external captureMessage: string => string = "captureMessage";

let initSentry = (~environment: Environment.t, ~dsn: string) => {
  Js.log("--sentry-re--");
  Js.log(dsn);
  Js.log(environment)
  switch (environment) {
  | Production
  | Development
  | Staging => {
      Js.log("here")
      Js.log(dsn);
      init(dsn)
  }
  };
};
