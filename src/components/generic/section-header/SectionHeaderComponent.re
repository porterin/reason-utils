[@react.component]
let make = (~heading: string) => {
  <div className="section-heading"> {React.string(heading)} </div>;
};
