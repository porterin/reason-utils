let handleClick = (event, onSelectCB) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    onSelectCB();
  };

[@react.component]
let make =
    (~className="", ~onSelectCB: unit => unit, ~children: React.element) =>
  <a
    className={"link " ++ className}
    onClick={event => handleClick(event, onSelectCB)}>
    children
  </a>;
