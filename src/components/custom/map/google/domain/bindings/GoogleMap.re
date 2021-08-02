// type config  TODO
type mapInst = Js.Json.t; //TODO to be kept in MapMod.lib payload

type config = {
  map_elem_id: string,
  center: LatLng.t,
  zoom: int,
  mapContainerClassName: option(string),
  clickableIcons: option(bool),
  onLoad: option(mapInst => unit),
  onTilesLoaded: option(unit => unit),
  options: option(Js.Json.t),
  ref: option(ReactDOMRe.domRef),
  onClick: option(unit => unit),
  mapTypeId: option(string),
  onBoundsChanged: option(unit => unit),
};

[@bs.module "@react-google-maps/api"] [@react.component]
external make:
  (
    ~center: LatLng.t,
    ~zoom: int,
    ~id: option(string)=?,
    ~mapContainerClassName: option(string),
    ~mapTypeId: option(string)=?,
    ~onBoundsChanged: option(unit => unit)=?,
    ~clickableIcons: option(bool),
    ~onClick: option(unit => unit)=?,
    ~onLoad: option(MapMod.mapInst => unit),
    ~onTilesLoaded: option(unit => unit),
    ~onIdle: option(unit => unit)=?,
    ~options: option(Js.Json.t),
    ~ref: option(ReactDOMRe.domRef),
    ~children: React.element
  ) =>
  React.element =
  "GoogleMap";
