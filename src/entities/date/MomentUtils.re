open MomentRe;

type t = Js.Date.t;

let momentWithFormat = (date: string, format: string) => {
  date -> momentWithFormat(format)
}

let toDate = (~format: string, ~value: string): t => {
  Moment.toDate(momentWithFormat(value, format));
};

let toString = (~format: string, ~date: Js.Date.t) => {
  Moment.format(format, momentWithDate(date));
};

