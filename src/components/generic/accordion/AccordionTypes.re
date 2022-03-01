type header =
  | Text(string)
  | Custom(unit => React.element);

type t = {
  header,
  footer: React.element,
  body: React.element,
  onOpen: unit => unit,
};

let make_props =
    (
      ~header,
      ~footer: React.element,
      ~body: React.element,
      ~onOpen: unit => unit=() => (),
      (),
    )
    : t => {
  header,
  footer,
  body,
  onOpen,
};
