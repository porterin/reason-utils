let handleClick = (event, setIsOpen: unit) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    setIsOpen;
  };

let msgString = (~length: int=40, ~msg: string, ~isOpen: bool) =>
  if (isOpen) {
    msg;
  } else if (msg |> String.length < length) {
    msg;
  } else {
    msg->String.sub(0, length) ++ "...";
  };

[@react.component]
let make = (~className="", ~msg: string, ~length: int) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);
  <>
    {React.string(msgString(~length, ~msg, ~isOpen))}
    {msg |> String.length > length
       ? <a
           className={"link " ++ className}
           onClick={event => handleClick(event, setIsOpen(_ => !isOpen))}>
           {React.string(isOpen ? " See Less" : " See More")}
         </a>
       : React.null}
  </>;
};
