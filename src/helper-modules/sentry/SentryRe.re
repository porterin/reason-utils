type static;

let ignoreErrors = [|
  [%re "/Cannot read property 'getReadModeExtract' of undefined/i"],
  [%re "/Cannot read property 'getReadModeRender' of undefined/i"],
  [%re "/Cannot read property 'getReadModeConfig' of undefined/i"],
  [%re "/ibFindAllVideos is not defined/i"],
|];

type init_options = {
  dsn: string,
  attachStackTrace: bool,
  ignoreErrors: array(Js_re.t),
};

[@bs.module "@sentry/browser"] external init: init_options => unit = "init";
[@bs.module "@sentry/browser"] external captureException: Js.Exn.t => static = "captureException";
[@bs.module "@sentry/browser"]
external capturePromiseError: Js.Promise.error => static = "captureException";
[@bs.module "@sentry/browser"] external captureMessage: string => string = "captureMessage";
[@bs.module "@sentry/browser"] external setTag: (string, string) => unit = "setTag";

let initSentry =
    (~environment: Environment.t, ~dsn: string, ~suppressErrors: array(Js_re.t)=[||], ()) => {
  let errors = Array.concat([suppressErrors, ignoreErrors]);
  switch (environment) {
  | Production => init({dsn, attachStackTrace: true, ignoreErrors: errors})
  | _ => ()
  };
};
