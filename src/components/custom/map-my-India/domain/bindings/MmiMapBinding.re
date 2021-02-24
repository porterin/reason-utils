/* Object creation */
[@bs.scope "MapmyIndia"] [@bs.new]
external createMap: (string, MmiMap.options) => MmiBaseType.map = "Map";

[@bs.scope "L"] [@bs.new]
external createLatLngBounds: array(LatLng.t) => LatLng.bounds =
  "latLngBounds";

/* Methods */

/* https://leafletjs.com/reference-1.6.0.html#latlng-distanceto */
[@bs.send] external distanceTo: (LatLng.t, LatLng.t) => float = "distanceTo";

/* https://leafletjs.com/reference-1.6.0.html#map-fitbounds */
[@bs.send]
external fitBounds: (MmiBaseType.map, LatLng.bounds, LatLng.boundOptions) => _ =
  "fitBounds";

/* https://leafletjs.com/reference-1.6.0.html#map-flytobounds */
[@bs.send]
external flyToBounds: (MmiBaseType.map, LatLng.bounds) => _ = "flyToBounds";

/* https://leafletjs.com/reference-1.6.0.html#map-getboundszoom */
[@bs.send]
external getBoundsZoom: (MmiBaseType.map, LatLng.bounds, bool) => int =
  "getBoundsZoom";

/* https://leafletjs.com/reference-1.6.0.html#map-panto */
[@bs.send] external panTo: (MmiBaseType.map, LatLng.t) => _ = "panTo";

/* https://leafletjs.com/reference-1.6.0.html#map-flyto */
[@bs.send] external flyTo: (MmiBaseType.map, LatLng.t, int) => _ = "flyTo";

/*
  https://leafletjs.com/reference-1.6.0.html#map-zoomstart
  https://leafletjs.com/reference-1.6.0.html#map-zoomend
  https://leafletjs.com/reference-1.6.0.html#evented-on
 */
[@bs.send]
external on:
  (
    MmiBaseType.map,
    [@bs.string] [
      | `zoomend(_ => _)
      | `zoomstart(_ => _)
      | `zoom(_ => _)
      | `moveend(_ => _)
      | `movestart(_ => _)
      | `move(_ => _)
      | `click(_ => _)
      | `dblclick(_ => _)
    ]
  ) =>
  MmiBaseType.map =
  "on";
/* https://leafletjs.com/reference-1.6.0.html#latlngbounds-pad */
[@bs.send] external setPad: (LatLng.bounds, float) => LatLng.bounds = "pad";
