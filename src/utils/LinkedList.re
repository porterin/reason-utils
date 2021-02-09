exception Empty_list;

module type LinkedList = {
  type t;
  type linkedList('t) =
    | Empty
    | List('t, linkedList('t));
  let empty: linkedList('t);
  let head: linkedList('t) => 't;
  let tail: linkedList('t) => linkedList('t);
  let insert: ('t, linkedList('t)) => linkedList('t);
  let remove: ('t, linkedList('t)) => linkedList('t);
  let contains: ('t, linkedList('t)) => bool;
  let iter: ('t => unit, linkedList('t)) => unit;
  let map: ('a => 'b, linkedList('a)) => linkedList('b);
  let fold: ('a => 'b, 'b, linkedList('a)) => 'b;
  let toArray: linkedList('t) => array('t);
  /* let fromArray: array('t) => linkedList('t); */
  let toList: linkedList('t) => list('t);
  let fromList: list('t) => linkedList('t);
  let isEmpty: linkedList('t) => bool;
  let size: linkedList('t) => int;
  let previousValue: ('t, linkedList('t), option('t)) => option('t);
};

module LinkedList = {
  type t;
  type linkedList('t) =
    | Empty
    | List('t, linkedList('t));
  let empty = Empty;
  let head = list =>
    switch (list) {
    | Empty => raise(Empty_list)
    | List(head, _tail) => head
    };
  let tail = list =>
    switch (list) {
    | Empty => Empty
    | List(_head, tail) => tail
    };
  let rec insert = (value, list) =>
    switch (list) {
    | Empty => List(value, Empty)
    | List(head, tail) => List(head, insert(value, tail))
    };
  let rec remove = (value, list) =>
    switch (list) {
    | Empty => Empty
    | List(head, Empty) =>
      if (head === value) {
        Empty;
      } else {
        list;
      }
    | List(head, List(nextHead, nextTail) as tail) =>
      if (head === value) {
        List(nextHead, nextTail);
      } else {
        List(head, remove(value, tail));
      }
    };
  let rec contains = (value, list) =>
    switch (list) {
    | Empty => false
    | List(head, tail) =>
      if (head === value) {
        true;
      } else {
        contains(value, tail);
      }
    };
  let rec iter = (fn, list) =>
    switch (list) {
    | Empty => ()
    | List(head, Empty) => fn(head)
    | List(head, tail) =>
      fn(head) |> ignore;
      iter(fn, tail);
    };
  let rec map = (fn, list) =>
    switch (list) {
    | Empty => Empty
    | List(head, tail) => List(fn(head), map(fn, tail))
    };
  let rec fold = (fn, acc, list) =>
    switch (list) {
    | Empty => acc
    | List(head, tail) => fold(fn, fn(acc, head), tail)
    };
  let toArray = lnklst => fold((acc, a) => Array.concat([acc, [|a|]]), [||], lnklst);
  let tolist = list => fold((acc, a) => List.concat([acc, [a]]), [], list);
  let fromList = (lst: list('t)): linkedList('t) => {
    let rec convertFromList = (~lst: list('a), ~lnklst: linkedList('a)=Empty, ()) => {
      switch (lst) {
      | [] => lnklst
      | [head, ...tail] => List(head, convertFromList(~lst=tail, ~lnklst, ()))
      };
    };
    convertFromList(~lst, ());
  };
  let isEmpty = list =>
    switch (list) {
    | Empty => true
    | _ => false
    };
  let size = list =>
    switch (list) {
    | Empty => 0
    | _ =>
      let count = ref(0);
      iter(_ => count := count^ + 1, list);
      count^;
    };
  let rec previousValue = (value: 't, lnklst: linkedList('t), previous: option('t)) => {
    switch (lnklst) {
    | Empty => previous
    | List(_head, Empty) => previous
    | List(head, List(_nextHead, _nextTail) as tail) =>
      if (head === value) {
        previous;
      } else {
        previousValue(value, tail, Some(head));
      }
    };
  };
};
