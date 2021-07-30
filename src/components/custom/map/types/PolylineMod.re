let defaultOpacity = 1.0;
let defaultWeight = 4;
let defaultLineColour = "#1E90FF"; //blue colour
let defaultVisibileStaus = true;


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
      ~visible: bool=defaultVisibileStaus,
      ~color: option(string)=Some(defaultLineColour),
      ~opacity: option(float)=Some(defaultOpacity),
      ~weight: option(int)=Some(defaultWeight),
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
