exception SupportedLanguages_fromString_Not_found;
type language =
  | English
  | Hindi
  | Kannada
  | Tamil
  | Telugu;

let fromString = (language: string) => {
  switch (language) {
  | "en" => English
  | "hi" => Hindi
  | "kn" => Kannada
  | "ta" => Tamil
  | "te" => Telugu
  | _ => raise(SupportedLanguages_fromString_Not_found)
  };
};
