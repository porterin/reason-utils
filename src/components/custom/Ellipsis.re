[@react.component]
let make = (~content: string, ~limit: int=30) => {
  let (isHover, setIsHover) = React.useState(_ => false);
  let actualLimit = limit < String.length(content) ? limit : String.length(content);
  let tail = limit < String.length(content) ? "..." : "";

  <div onMouseOver={_ => setIsHover(_ => true)} onMouseOut={_ => setIsHover(_ => false)}>
    {React.string(isHover ? content : String.sub(content, 0, actualLimit) ++ tail)}
  </div>;
};
