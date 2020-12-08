module StringMap =
  Map.Make({
    type t = string;
    let compare = compare;
  });
