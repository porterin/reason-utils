type t('a) = {
  head: 'a,
  tail: list('a),
};

let make: list('a) => option(t('a)) =
  fun
  | [head, ...tail] => Some({head, tail})
  | [] => None;

let toT = (head: 'a, tail: list('a)): t('a) => {
  {head, tail};
};

let toList: t('a) => list('a) =
  fun
  | {head, tail} => List.append([head], tail);

let listFunc = (funcDef: list('a) => list('b), l: t('a)): t('b) => {
  let (list_head, list_tail) = (funcDef([l.head]), funcDef(l.tail));
  toT(List.nth(list_head, 0), list_tail);

};

let delegateToList = (funcDef: list('a) => 'c, l: t('a)): 'c => {
  funcDef(l |> toList);
};

let t_decode = (
  json: Js.Json.t, 
  decoder: Js.Json.t => Belt.Result.t(
    'a,
    Decco.decodeError
  )) => {
  decoder 
    -> Decco.listFromJson(json) 
    -> Catalyst.DeccoUtils.resolveResult("NonEmptyList.re")
    -> make
}