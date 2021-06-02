type mapInst = Js.Json.t; // Need to figure out the appropriate type def. Not verified to work with MMI
// TODO: make lib with mapInst as payload
type lib =
  | GoogleMap
  | MMI;

type loadConfig =
  | GoogleMap(LoadScript.load_config)
  | MMI(string)

type config = {
  map_elem_id: string,
  center: Catalyst.LatLng.t,
  zoom: option(int),
  zoom_control: option(bool),
  hybrid: option(bool),
  mapContainerClassName: option(string),
  mapTypeId: option(string),
  onBoundsChanged: option(unit => unit),
  clickableIcons: option(bool),
  onClick: option(unit => unit),
  onLoad: option(mapInst => unit),
  onTilesLoaded: option(unit => unit),
  options: option(Js.Json.t),
  ref: option(ReactDOMRe.domRef),
};

let defaultOptions =
  Json.Encode.object_([
    ("gestureHandling", Json.Encode.string("greedy")),
    ("maxZoom", Json.Encode.int(18)),
    ("minZoom", Json.Encode.int(9)),
  ]);

let make_props =
    (
      ~map_elem_id: string,
      ~center: Catalyst.LatLng.t,
      ~zoom: option(int)=Some(11),
      ~zoom_control: option(bool)=Some(true),
      ~hybrid: option(bool)=Some(false),
      ~mapContainerClassName: option(string)=?,
      ~mapTypeId: option(string)=?,
      ~onBoundsChanged: option(unit => unit)=?,
      ~clickableIcons: option(bool)=Some(false),
      ~onClick: option(unit => unit)=?,
      ~onLoad: option(mapInst => unit)=?,
      ~onTilesLoaded: option(unit => unit)=?,
      ~options: option(Js.Json.t)=Some(defaultOptions),
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    )
    : config => {
  map_elem_id,
  center,
  zoom,
  zoom_control,
  hybrid,
  mapContainerClassName,
  mapTypeId,
  onBoundsChanged,
  clickableIcons,
  onClick,
  onLoad,
  onTilesLoaded,
  options,
  ref,
};
