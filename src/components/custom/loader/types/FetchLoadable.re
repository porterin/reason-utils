type t('a) =
  | Loading(option('a))
  | Live('a)
  | Error(Error.t);
