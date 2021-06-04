let getGoogleConfig = (config: PolylineMod.config): GooglePolyline.config => {
  path: config.path,
  visible: config.visible,
  options: {
    strokeColor: config.color,
    strokeOpacity: config.opacity,
    strokeWeight: config.weight,
  },
  ref: config.ref,
};

[@react.component]
let make = (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: PolylineMod.config) => {
  switch (lib_name) {
  | MapMod.GoogleMap =>
    let googleConfig = getGoogleConfig(config);
    <GooglePolyline
      path={googleConfig.path}
      visible={googleConfig.visible}
      options={googleConfig.options}
      ref={googleConfig.ref}
    />;
  | MapMod.MMI => React.null
  };
};
