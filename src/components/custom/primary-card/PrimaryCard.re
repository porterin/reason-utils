let getHeader =
    (~title: CommonTypes.viewText, ~action: option(ButtonTypes.buttonProps)): React.element => {
  <div className="header">
    <div className="title">
      {switch (title) {
       | Text(t) => React.string(t)
       | NoText => React.null
       | Custom(fn) => fn()
       }}
    </div>
    {switch (action) {
     | None => React.null
     | Some(action) => <RoundedPrimaryButton buttonProps=action />
     }}
  </div>;
};

[@react.component]
let make =
    (
      ~title: CommonTypes.viewText,
      ~action: option(ButtonTypes.buttonProps),
      ~className: string="",
      ~children,
    ) => {
  <div className={"primary-card " ++ className}>
    {getHeader(~title, ~action)}
    <div className="body"> children </div>
  </div>;
};
