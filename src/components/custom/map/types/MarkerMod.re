type icon =
  | Img(string)
  | Elem(React.element);

type markerData = {
  location: LatLng.t,
  icon_data: icon,
  tooltip: ToolTipInfo.t,
};

type config = {
  position: LatLng.t,
  clickable: option(bool),
  visible: option(bool),
  zIndex: option(int),
  icon: option(string),
  anchor: option(array(int)),
  opacity: option(float),
  onMouseOver: option(ReactEvent.Mouse.t => unit),
  onMouseOut: option(ReactEvent.Mouse.t => unit),
  onClick: option(ReactEvent.Mouse.t => unit),
  onPositionChanged: option(unit => unit),
  ref: option(ReactDOMRe.domRef),
};

let make_props =
    (
      ~position: LatLng.t,
      ~clickable: option(bool)=Some(false),
      ~visible: option(bool)=Some(true),
      ~zIndex: option(int)=None,
      ~icon: option(string)=None,
      ~anchor: option(array(int))=Some([|0, 0|]),
      ~opacity: option(float)=Some(1.0),
      ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onPositionChanged: option(unit => unit)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  position,
  clickable,
  visible,
  zIndex,
  icon,
  anchor,
  opacity,
  onMouseOver,
  onMouseOut,
  onClick,
  onPositionChanged,
  ref,
};
