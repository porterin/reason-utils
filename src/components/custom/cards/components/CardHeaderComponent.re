[@react.component]
let make = (~title: string, ~actionBtn: option(ActionButtonType.t)) =>
  <div className="card-component__header-container">
    <div className="card-component__header-title"> {React.string(title)} </div>
    <div className="card-component__action-btns">
      {switch (actionBtn) {
       | Some(actionBtn) => <ActionBtn button=actionBtn />
       | None => React.null
       }}
    </div>
  </div>;
