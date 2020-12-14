type t =
  | String(string)
  | Number(string)
  | Msisdn(string)
  | Mobile(string);

type res = Belt.Result.t(t, string);
