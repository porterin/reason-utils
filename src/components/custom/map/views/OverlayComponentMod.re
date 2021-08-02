let getGoogleConfig = (config: OverlayViewMod.config): GoogleOverlayView.config => {
  position: config.position,
  mapPaneName: {
    Belt.Option.getWithDefault(config.mapPaneName, "markerLayer");
  },
  getPixelPositionOffset: Some(config.getPixelPositionOffset),
  wrappedChildren: config.wrappedChildren,
  ref: config.ref,
};

[@react.component]
let make = (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: OverlayViewMod.config) => {
  switch (lib_name) {
  | MapMod.GoogleMap =>
    let googleConfig = getGoogleConfig(config);
    <GoogleOverlayView
      position={googleConfig.position}
      mapPaneName={googleConfig.mapPaneName}
      getPixelPositionOffset={googleConfig.getPixelPositionOffset}>
      {googleConfig.wrappedChildren}
    </GoogleOverlayView>;
  | MapMod.MMI => React.null
  };
};
