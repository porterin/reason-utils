[@react.component]
let make = (~button: ActionButtonType.t) =>
  <div className="card-component__action-btn-container">
    {switch (button.text) {
     | Some(text) =>
       <a
         className="btn-tertiary--blue"
         onClick={_event => button.callback()}>
         {React.string(text)}
       </a>
     | None =>
       <a
         className="btn-tertiary--blue"
         onClick={_event => button.callback()}>
         {React.string("View more")}
       </a>
     }}
  </div>;

