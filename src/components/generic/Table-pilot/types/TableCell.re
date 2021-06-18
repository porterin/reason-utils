type linkActionCallback = unit => unit;

type t = 
  | Text(string)
  | Date({format: string, date: Date.t})
  | Status({color: ColorPalette.t, text: string})
  | ActionButton(string, linkActionCallback)
  | RedirectLink(string, string)
  | Custom(unit => React.element);
  
