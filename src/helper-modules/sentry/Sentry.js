import * as Sentry from '@sentry/browser';
var SENTRY_FRONTEND_DSN = 'https://4ce8c888a1d349428e0dfeb0cb325a71@sentry.io/1408218';

export function init(env) {
  if (env == "production") {
    Sentry.init({
      dsn: SENTRY_FRONTEND_DSN,
      attachStackTrace: true
    })
  }
}

/* TODO: Create proper bindings */
export function captureException(exn) {
  Sentry.captureException(exn);
}

/* TODO: Create proper bindings */
export function capturePromiseError(promise_err) {
  Sentry.captureException(promise_err);
}

/* TODO: Create proper bindings */
export function captureMessage(str) {
  Sentry.captureMessage(str);
}
