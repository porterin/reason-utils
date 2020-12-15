let getHeader =
    (~title: string, ~action: option(ButtonTypes.buttonProps)): React.element => {
  <div className="header">
    <div className="title"> {React.string(title)} </div>
    {switch (action) {
     | None => React.null
     | Some(action) => <RoundedPrimaryButton buttonProps=action />
     }}
  </div>;
};

[@react.component]
let make =
    (
      ~title: string,
      ~action: option(ButtonTypes.buttonProps),
      ~className: string="",
      ~children,
    ) => {
  <div className={"primary-card " ++ className}>
    {getHeader(~title, ~action)}
    <div className="body"> children </div>
  </div>;
};
