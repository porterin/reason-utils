exception SupportedLanguages_fromString_Not_found;
type language =
  | English
  | Hindi
  | Kannada
  | Tamil
  | Telugu
  | Marathi;

let fromString = (language: string) => {
  switch (language) {
  | "en" => English
  | "hi" => Hindi
  | "kn" => Kannada
  | "ta" => Tamil
  | "te" => Telugu
  | "mr" => Marathi
  | _ => raise(SupportedLanguages_fromString_Not_found)
  };
};
