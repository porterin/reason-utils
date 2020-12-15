type t('a) =
  | Init
  | Loading(option('a))
  | Live('a)
  | Error(Error.t);
