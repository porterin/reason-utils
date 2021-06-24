type t =
  | Text(string)
  | NoText
  | Custom(unit => React.element);

let resolve = (text: t): React.element => {
  switch (text) {
  | Text(msg) => React.string(msg)
  | NoText => React.null
  | Custom(fn) => fn()
  };
};
