type polylineOptions = {
  strokeColor: option(string),
  strokeOpacity: option(float),
  strokeWeight: option(int),
};

type config = {
  path: array(LatLng.t),
  visible: bool,
  options: polylineOptions,
  ref: option(ReactDOMRe.domRef),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~path: array(LatLng.t),
    ~visible: option(bool)=?,
    ~options: polylineOptions=?,
    ~ref: option(ReactDOMRe.domRef)
  ) =>
  React.element =
  "Polyline";
