type error =
  | SmallerThanSmallest
  | LargerThanLargest;

let rec binarySearch =
        (
          searchValue: 'a,
          input: array('a),
          startIndex,
          endIndex,
          comparator: ('a, 'a) => int,
        )
        : Belt.Result.t((int, int), error) => {
  switch (searchValue) {
  | res when comparator(input[Array.length(input) - 1], res) === 1 =>
    Belt.Result.Error(LargerThanLargest)
  | res when comparator(input[0], res) === (-1) =>
    Belt.Result.Error(SmallerThanSmallest)
  | _ =>
    let mid = (startIndex + endIndex) / 2;
    switch (mid) {
    | _res when startIndex > endIndex =>
      Belt.Result.Ok((endIndex, startIndex))
    | res when comparator(input[res], searchValue) === 0 =>
      Belt.Result.Ok((mid, mid))
    | res when comparator(input[res], searchValue) === (-1) =>
      binarySearch(searchValue, input, startIndex, mid - 1, comparator)
    | _ => binarySearch(searchValue, input, mid + 1, endIndex, comparator)
    };
  };
};
