type config = {
  position: Catalyst.LatLng.t,
  mapPaneName: option(string),
  onMouseOver: option(ReactEvent.Mouse.t => unit),
  onMouseOut: option(ReactEvent.Mouse.t => unit),
  onClick: option(ReactEvent.Mouse.t => unit),
  ref: option(ReactDOMRe.domRef),
};

let make_props =
    (
      ~position: Catalyst.LatLng.t,
      ~mapPaneName: option(string)=Some("overlayMouseTarget"),
      ~onMouseOver: option(ReactEvent.Mouse.t => unit)=None,
      ~onMouseOut: option(ReactEvent.Mouse.t => unit)=None,
      ~onClick: option(ReactEvent.Mouse.t => unit)=None,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  position,
  mapPaneName,
  onMouseOver,
  onMouseOut,
  onClick,
  ref,
};
