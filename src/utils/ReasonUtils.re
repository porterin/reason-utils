let checkForEmptyString = (string: string): bool =>
  switch (Js.String.trim(string)) {
  | "" => true
  | _ => false
  };

let nbsp = [%bs.raw {|'\u0020'|}];

let ignoreUnused = (value: 'a) => {
  let _ = value;
};
