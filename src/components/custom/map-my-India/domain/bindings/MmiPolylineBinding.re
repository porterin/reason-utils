[@bs.scope "L"] [@bs.new]
external createPolyline:
  (~pos: array(LatLng.t), ~opt: Polyline.options=?, unit) =>
  MmiBaseType.polyline =
  "polyline";

[@bs.send]
external addPolylineToMap:
  (MmiBaseType.polyline, MmiBaseType.map) => MmiBaseType.polyline =
  "addTo";

[@bs.send]
external removePolylineFromMap:
  (MmiBaseType.polyline, MmiBaseType.map) => MmiBaseType.polyline =
  "removeFrom";
