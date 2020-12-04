let snakeCaseToTitleCase = (text: string): string => {
  let a =
    text
    |> Js.String.split("_")
    |> Array.map(a =>
         Js.String.toUpperCase(Js.String.charAt(0, a))
         ++ Js.String.substring(~from=1, ~to_=String.length(a), a)
         ++ " "
       );
  Js.String.concatMany(a, " ");
};

let getFirstCharacters = (str: string, length: int) =>
  try(String.sub(str, 0, length)) {
  | _ => str
  };

let getStringOptional = (str: string): option(string) =>
  switch (str) {
  | "" => None
  | nonEmptyString => Some(nonEmptyString)
  };

let maybeGetTrimmedString = (input: string): option(string) =>
  String.(input |> trim |> length) > 0 ? Some(input) : None;
