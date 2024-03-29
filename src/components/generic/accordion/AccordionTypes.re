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
      ~header: header,
      ~footer: React.element=React.null,
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
