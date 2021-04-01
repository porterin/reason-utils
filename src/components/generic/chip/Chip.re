module Size = {
  type t =
    | Small
    | Medium;
  let make = (s: t) => {
    switch (s) {
    | Small => `Small
    | Medium => `Medium
    };
  };
};

[@react.component]
let make = (~title: CommonTypes.viewText, ~size: Size.t=Small) => {
  <MaterialUi.Chip
    label={
      switch (title) {
      | Text(t) => React.string(t)
      | NoText => React.null
      | Custom(fn) => fn()
      }
    }
    size={Size.make(size)}
  />;
};
