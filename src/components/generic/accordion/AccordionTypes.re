type header =
  | Text(string)
  | Custom(unit => React.element);

type t = {
  header,
  footer: React.element,
  body: React.element,
};
