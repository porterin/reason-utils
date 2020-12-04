type t =
  | Text(string)
  | Custom(unit => React.element)
  | Href(string, string);
