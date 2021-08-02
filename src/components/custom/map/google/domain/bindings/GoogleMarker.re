type icon = {
  url: string,
  anchor: Point.t,
};

type marker = Js.Json.t;

type config = {
  position: LatLng.t,
  clickable: option(bool),
  visible: option(bool),
  zIndex: option(int),
  icon: option(icon),
  onPositionChanged: option(unit => unit),
  onMouseOver: option(ReactEvent.Mouse.t => unit),
  onMouseOut: option(ReactEvent.Mouse.t => unit),
  onClick: option(ReactEvent.Mouse.t => unit),
  opacity: option(float),
  ref: option(ReactDOMRe.domRef),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~position: LatLng.t,
    ~clickable: option(bool),
    ~visible: option(bool),
    ~zIndex: option(int),
    ~icon: option(icon),
    ~onPositionChanged: option(unit => unit),
    ~onMouseOver: option(ReactEvent.Mouse.t => unit),
    ~onMouseOut: option(ReactEvent.Mouse.t => unit),
    ~onClick: option(ReactEvent.Mouse.t => unit),
    ~opacity: option(float)=?,
    ~ref: option(ReactDOMRe.domRef),
    ~children: React.element
  ) =>
  React.element =
  "Marker";
