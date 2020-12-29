type linkActionCallback = unit => unit;

type t = 
  | Text(string)
  | ActionButton(string, linkActionCallback)
  | RedirectLink(string, string)
  | Custom(unit => React.element);
  
