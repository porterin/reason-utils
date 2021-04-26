type linkActionCallback = unit => unit;

type t = 
  | Text(string)
  | Status({color: ColorPalette.t, text: string})
  | ActionButton(string, linkActionCallback)
  | RedirectLink(string, string)
  | Custom(unit => React.element);
  
