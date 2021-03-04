import * as Sentry from '@sentry/browser';

let ignoreErrors = [
  /Cannot read property 'getReadModeExtract' of undefined/i,
  /Cannot read property 'getReadModeRender' of undefined/i,
  /Cannot read property 'getReadModeConfig' of undefined/i,
  /ibFindAllVideos is not defined/i,
]

export function init(environment, dsn) {
  if (environment == "production") {
    Sentry.init({
      dsn,
      attachStackTrace: true,
      ignoreErrors
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
