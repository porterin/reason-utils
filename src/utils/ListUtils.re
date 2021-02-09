/* reading lists */
let slice = (list, start, range) => {
  let rec drop = (n, list) =>
    switch (list) {
    | [] => []
    | [_, ...xs] as z => n == 0 ? z : drop(n - 1, xs)
    };
  let rec take = (n, list) =>
    switch (list) {
    | [] => []
    | [x, ...xs] => n == 0 ? [] : [x, ...take(n - 1, xs)]
    };
  take(range, drop(start, list));
};

let find = (lst: list('a), fn: 'a => bool) =>
  try(lst |> List.find(fn) |> (result => Some(result))) {
  | Not_found => None
  };

let rec findIndex = (~i=0, lst, f) => {
  switch (lst) {
  | [] => None
  | [hd, ...tail] => f(hd) ? Some(i) : findIndex(~i=i + 1, tail, f)
  };
};

let rec getElementAt = (~index: int, l: list('a)) =>
  switch (l) {
  | [] => None
  | [head, ...tail] => index <= 0 ? Some(head) : getElementAt(~index=index - 1, tail)
  };

let rec calculateSum = (l: list(int)) =>
  switch (l) {
  | [] => 0
  | [head, ...tail] => head + calculateSum(tail)
  };

let rec calculateSumForFloats = (l: list(float)) =>
  switch (l) {
  | [] => 0.
  | [head, ...tail] => head +. calculateSumForFloats(tail);
  };


/* changing lists */
let rec removeItem = (~value: 'a, l: list('a)) =>
  switch (l) {
  | [] => []
  | [head, ...tail] when head == value => removeItem(~value, tail)
  | [head, ...tail] => [head, ...removeItem(~value, tail)]
  };

let rec replaceItem = (~value: 'a, ~with_: 'a, l: list('a)) =>
  switch (l) {
  | [] => []
  | [head, ...tail] when head == value => [with_, ...replaceItem(~value, ~with_, tail)]
  | [head, ...tail] => [head, ...replaceItem(~value, ~with_, tail)]
  };

/* creating lists */
let rec range = (start: int, end_: int) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };

/* unique list */
let unique = (list_input: list('a)): list('a) => {
  let rec uniqueList = (~new_list: list('a), old_list: list('a)) => {
    switch (old_list) {
    | [] => List.rev(new_list)
    | [head, ...tail] =>
      List.exists(list_item => list_item == head, new_list)
        ? uniqueList(tail, ~new_list) : uniqueList(tail, ~new_list=[head, ...new_list])
    };
  };
  list_input |> uniqueList(~new_list=[]);
};
