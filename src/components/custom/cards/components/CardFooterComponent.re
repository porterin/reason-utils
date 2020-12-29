[@react.component]
let make = (~actionBtn: option(ActionButtonType.t)) => {
  switch (actionBtn) {
  | Some(actionBtn) =>
    <div className="card-component__footer-container"> {<ActionBtn button=actionBtn />} </div>
  | None => React.null
  };
};
