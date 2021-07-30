type size = {
  width: int,
  height: int,
};

type infoWindowOptions = {pixelOffset: size};

type config = {
  position: option(LatLng.t),
  options: option(infoWindowOptions),
  ref: option(ReactDOMRe.domRef),
  onCloseClick: option(unit => unit),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~position: option(LatLng.t),
    ~options: option(infoWindowOptions),
    ~zIndex: option(int)=?,
    ~onCloseClick: option(unit => unit)=?,
    ~ref: option(ReactDOMRe.domRef)=?,
    ~children: React.element
  ) =>
  React.element =
  "InfoWindow";
