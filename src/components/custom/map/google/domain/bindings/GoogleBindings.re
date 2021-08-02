[@bs.send] external fitBounds: (MapMod.mapInst, Catalyst.LatLng.bounds) => _ = "fitBounds";
[@bs.send] external getBounds: MapMod.mapInst => Catalyst.LatLng.bounds = "getBounds";

[@bs.send]
external extend: (Catalyst.LatLng.bounds, Catalyst.LatLng.t) => Catalyst.LatLng.bounds = "extend";
[@bs.scope ("window", "google", "maps")] [@bs.new]
external createGoogleLatLngBounds: _ => Catalyst.LatLng.bounds = "LatLngBounds";

type latlng;
[@bs.scope ("window", "google", "maps")] [@bs.new]
external getGoogleLatLng: Catalyst.LatLng.t => latlng = "LatLng";
[@bs.scope ("window", "google", "maps", "geometry", "spherical")] [@bs.val]
external computeDistanceBetween: (latlng, latlng) => float = "computeDistanceBetween";
