[@bs.send] external fitBounds: (MapMod.mapInst, LatLng.bounds) => _ = "fitBounds";
[@bs.send] external getBounds: MapMod.mapInst => LatLng.bounds = "getBounds";

[@bs.send]
external extend: (LatLng.bounds, LatLng.t) => LatLng.bounds = "extend";
[@bs.scope ("window", "google", "maps")] [@bs.new]
external createGoogleLatLngBounds: _ => LatLng.bounds = "LatLngBounds";

type latlng;
[@bs.scope ("window", "google", "maps")] [@bs.new]
external getGoogleLatLng: LatLng.t => latlng = "LatLng";
[@bs.scope ("window", "google", "maps", "geometry", "spherical")] [@bs.val]
external computeDistanceBetween: (latlng, latlng) => float = "computeDistanceBetween";
