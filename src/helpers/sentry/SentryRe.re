[@bs.module "./Sentry.js"] external initSentryConfig: string => unit = "init";
[@bs.module "./Sentry.js"] external captureException: string => string = "captureException";
