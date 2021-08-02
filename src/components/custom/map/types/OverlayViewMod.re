let getWrappedChildren =
    (
      children: React.element,
      onMouseOver: option(ReactEvent.Mouse.t => unit),
      onMouseOut: option(ReactEvent.Mouse.t => unit),
      onClick: option(ReactEvent.Mouse.t => unit),
    ) => {
  <div
    onMouseOut={Belt.Option.getWithDefault(onMouseOut, _ => ())} //Not part of the library, added for functionality
    onMouseOver={Belt.Option.getWithDefault(onMouseOver, _ => ())} //Not part of the library, added for functionality
    onClick={Belt.Option.getWithDefault(onClick, _ => ())}>
    //Not part of the library, added for functionality
     children </div>;
};

let getPixelPositionOffset = (width: int, height: int): Point.t => {x: - (width / 2), y: - height};

type config = {
  position: Catalyst.LatLng.t,
  mapPaneName: option(string),
  children: React.element,
  wrappedChildren: React.element,
  getPixelPositionOffset: (int, int) => Point.t,
  ref: option(ReactDOMRe.domRef),
};

let make_props =
    (
      ~position: Catalyst.LatLng.t,
      ~mapPaneName: option(string)=Some("overlayMouseTarget"),
      ~onMouseOver: option(ReactEvent.Mouse.t => unit)=None,
      ~onMouseOut: option(ReactEvent.Mouse.t => unit)=None,
      ~onClick: option(ReactEvent.Mouse.t => unit)=None,
      ~children: React.element,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  position,
  mapPaneName,
  children,
  wrappedChildren: getWrappedChildren(children, onMouseOver, onMouseOut, onClick),
  getPixelPositionOffset,
  ref,
};