type config = {
  position: Catalyst.LatLng.t,
  mapPaneName: string,
  getPixelPositionOffset: option((int, int) => Point.t),
  wrappedChildren: React.element,
  ref: option(ReactDOMRe.domRef),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~position: Catalyst.LatLng.t,
    ~mapPaneName: string,
    ~getPixelPositionOffset: option((int, int) => Point.t),
    ~ref: option(ReactDOMRe.domRef)=?,
    ~children: React.element
  ) =>
  React.element =
  "OverlayView";
