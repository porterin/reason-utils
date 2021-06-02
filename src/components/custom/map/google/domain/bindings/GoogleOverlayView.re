type point = {
  x: int,
  y: int,
};

type config = {
  position: LatLng.t,
  mapPaneName: string,
  getPixelPositionOffset: option((int, int) => point),
  ref: option(ReactDOMRe.domRef),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~position: LatLng.t,
    ~mapPaneName: string,
    ~getPixelPositionOffset: option((int, int) => point),
    ~ref: option(ReactDOMRe.domRef)=?,
    ~children: React.element
  ) =>
  React.element =
  "OverlayView";
