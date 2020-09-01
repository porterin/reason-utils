import * as Sentry from "@sentry/browser";

export function init(dsn) {
  Sentry.init({
    dsn: dsn
  });
}

/* TODO: Create proper bindings */
export function captureException(str) {
  Sentry.captureException(new Error(str));
}
