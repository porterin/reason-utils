let getGoogleConfig = (config: MarkerMod.config): GoogleMarker.config => {
  position: config.position,
  clickable: config.clickable,
  visible: config.visible,
  zIndex: config.zIndex,
  icon:
    switch (config.icon, config.anchor) {
    | (Some(iconUrl), Some(anchorPoints)) =>
      Some({
        url: iconUrl,
        anchor: {
          x: anchorPoints[0],
          y: anchorPoints[1],
        },
      })
    | (_, _) => None
    },
  onMouseOver: config.onMouseOver,
  onMouseOut: config.onMouseOut,
  onClick: config.onClick,
  opacity: config.opacity,
  onPositionChanged: config.onPositionChanged,
  ref: config.ref,
};

[@react.component]
let make =
    (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: MarkerMod.config, ~children: React.element) => {
  switch (lib_name) {
  | MapMod.GoogleMap =>
    let googleConfig = getGoogleConfig(config);
    <GoogleMarker
      position={googleConfig.position}
      zIndex={googleConfig.zIndex}
      clickable={googleConfig.clickable}
      visible={googleConfig.visible}
      icon={googleConfig.icon}
      onMouseOver={googleConfig.onMouseOver}
      onMouseOut={googleConfig.onMouseOut}
      onClick={googleConfig.onClick}
      onPositionChanged={googleConfig.onPositionChanged}
      ref={googleConfig.ref}>
      children
    </GoogleMarker>;
  | MapMod.MMI => React.null
  };
};
