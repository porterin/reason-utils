type config = {
  position: option(Catalyst.LatLng.t),
  anchor: option(array(int)),
  zIndex: option(int),
  onCloseClick: option(unit => unit),
  ref: option(ReactDOMRe.domRef),
};

let make_props =
    (
      ~position: option(Catalyst.LatLng.t)=?,
      ~zIndex: option(int)=None,
      ~anchor: option(array(int))=None,
      ~onCloseClick: option(unit => unit)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  position,
  zIndex,
  anchor,
  onCloseClick,
  ref,
};
