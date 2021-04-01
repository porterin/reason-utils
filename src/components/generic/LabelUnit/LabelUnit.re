[@react.component]
let make = (~label: string, ~unit: string, ~className="") => {
  <Catalyst.Row className={"label-unit " ++ className}>
    <div className="label"> {React.string(label)} </div>
    <div className="unit"> {React.string("(" ++ unit ++ ")")} </div>
  </Catalyst.Row>;
};
