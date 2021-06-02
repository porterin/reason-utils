type config = {
  path: array(Catalyst.LatLng.t),
  color: option(string),
  visible: bool,
  opacity: option(float),
  weight: option(int),
  ref: option(ReactDOMRe.domRef),
};

let make_props =
    (
      ~path: array(Catalyst.LatLng.t),
      ~visible: bool=true,
      ~color: option(string)=?,
      ~opacity: option(float)=Some(1.0),
      ~weight: option(int)=Some(4),
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  path,
  visible,
  color,
  opacity,
  weight,
  ref,
};
