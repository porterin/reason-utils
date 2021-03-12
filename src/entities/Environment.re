type t =
  | Production
  | Staging
  | Development;

let fromString : (string) => t =
  fun
  | "production" => Production
  | "staging" => Staging
  | _ => Development;

let toString : (t) => string =
  fun
  | Production => "production"
  | Staging => "staging"
  | Development => "development";