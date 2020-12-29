[@react.component]
let make = (~message: string="Success") => {
  <div className="success-message"> {React.string(message)} </div>;
};
