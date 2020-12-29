let firstN = (range: int, inputArray: array('a)): array('a) =>
  try(Array.sub(inputArray, 0, range)) {
  | _ => Array.sub(inputArray, 0, Array.length(inputArray))
  };
