[@react.component]
let make = (~title: string, ~children=React.null) => {
  <div className="panel-heading-container">
    <div className="title"> {React.string(title)} </div>
    children
  </div>;
};
