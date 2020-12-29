[@react.component]
let make = (~className="", ~title: string) =>
  <div className={"text-styling-header font-size-14 " ++ className}> {React.string(title)} </div>;
