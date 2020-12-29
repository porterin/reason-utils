/* Object creation */
[@bs.scope "L"] [@bs.new]
external createLatLng: (float, float) => LatLng.t = "latLng";

[@bs.scope "L"] [@bs.new]
external createMarker:
  (~pos: LatLng.t, ~opts: option(Marker.options)=?, unit) =>
  MmiBaseType.marker =
  "marker";

/* Methods */
[@bs.send]
external addMarkerToMap:
  (MmiBaseType.marker, MmiBaseType.map) => MmiBaseType.marker =
  "addTo";

[@bs.send]
external removeMarkerFromMap:
  (MmiBaseType.marker, MmiBaseType.map) => MmiBaseType.marker =
  "removeFrom";

[@bs.send]
external setMarkerLatLng: (MmiBaseType.marker, LatLng.t) => MmiBaseType.marker =
  "setLatLng";

[@bs.send]
external on:
  (MmiBaseType.marker, [@bs.string] [ | `click(_ => _) | `move(_ => _)]) =>
  MmiBaseType.marker =
  "on";

[@bs.scope "L"] [@bs.new]
external setDivIcon: DivIcon.t => MmiBaseType.icon = "divIcon";

[@bs.scope "L"] [@bs.new]
external setIcon: Marker.imgIconOpts => MmiBaseType.icon = "icon";

[@bs.send]
external onMarker: (MmiBaseType.marker, string, _ => unit) => _ = "on";

[@bs.send] external offMarker: (MmiBaseType.marker, string) => _ = "off";

[@bs.obj]
external createMarkerOpts:
  (
    ~icon: option(MmiBaseType.icon)=?,
    ~title: option(string)=?,
    ~zIndexOffset: option(int)=?,
    ~riseOnHover: option(bool)=?,
    ~riseOffset: option(int)=?,
    ~opacity: option(float)=?,
    unit
  ) =>
  Marker.options;
