type header = 
  | Text(string) 
  | Custom(unit => React.element);

type t = {
  header: header,
  onHeaderExpand: React.element,
  body: React.element,
};
