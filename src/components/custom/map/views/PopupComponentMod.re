let getGoogleConfig = (config: PopupMod.config): GoogleInfoWindow.config => {
  position: config.position,
  options:
    switch (config.anchor) {
    | Some(anchorPoints) =>
      Some({
        pixelOffset: {
          width: anchorPoints[0],
          height: anchorPoints[1],
        },
      })
    | None => None
    },
  onCloseClick: config.onCloseClick,
  ref: config.ref,
};
[@react.component]
let make =
    (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: PopupMod.config, ~children: React.element) => {
  switch (lib_name) {
  | MapMod.GoogleMap =>
    let googleConfig = getGoogleConfig(config);
    <GoogleInfoWindow
      position=googleConfig.position
      options=googleConfig.options
      onCloseClick={googleConfig.onCloseClick->Belt.Option.getWithDefault(() => ())}>
      children
    </GoogleInfoWindow>
  | MapMod.MMI => React.null
  };
};
