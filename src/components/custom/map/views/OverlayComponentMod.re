let getPixelPositionOffset = (width: int, height: int): GoogleOverlayView.point => {
  x: - (width / 2),
  y: - height,
};

let getGoogleConfig = (config: OverlayViewMod.config): GoogleOverlayView.config => {
  position: config.position,
  mapPaneName: {
    Belt.Option.getWithDefault(config.mapPaneName, "markerLayer");
  },
  getPixelPositionOffset: Some(getPixelPositionOffset),
  ref: config.ref,
};

[@react.component]
let make = (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: OverlayViewMod.config, ~children: React.element) => {
  switch (lib_name) {
  | MapMod.GoogleMap =>
    let googleConfig = getGoogleConfig(config);
    <GoogleOverlayView
      position={googleConfig.position}
      mapPaneName={googleConfig.mapPaneName}
      getPixelPositionOffset={googleConfig.getPixelPositionOffset}>
      <div
        onMouseOut={Belt.Option.getWithDefault(config.onMouseOut, _ => ())}
        onMouseOver={Belt.Option.getWithDefault(config.onMouseOver, _ => ())}
        onClick={Belt.Option.getWithDefault(config.onClick, _ => ())}>
        children
      </div>
    </GoogleOverlayView>;
  | MapMod.MMI => React.null
  };
};
