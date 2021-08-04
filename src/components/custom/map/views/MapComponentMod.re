let getGoogleConfig = (config: MapMod.config): GoogleMap.config => {
  map_elem_id: config.map_elem_id,
  center: config.center,
  zoom: config.zoom->Belt.Option.getWithDefault(11),
  mapContainerClassName: config.mapContainerClassName,
  clickableIcons: config.clickableIcons,
  onLoad: config.onLoad,
  onTilesLoaded: config.onTilesLoaded,
  options: config.options,
  ref: config.ref,
  onClick: None,
  mapTypeId: None,
  onBoundsChanged: None,
};

[@react.component]
let make =
    (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: MapMod.config, ~loadConfig: MapMod.loadConfig, ~children: React.element) => {
  switch (lib_name,loadConfig) {
  | (MapMod.GoogleMap, MapMod.GoogleMap(loadConfig)) =>
    let googleConfig = getGoogleConfig(config);
    <LoadScript
      id="script-loader"
      googleMapsApiKey=loadConfig.googleMapsApiKey
      libraries=loadConfig.libraries>
      <GoogleMap
        id={googleConfig.map_elem_id}
        center={googleConfig.center}
        zoom={googleConfig.zoom}
        mapContainerClassName={googleConfig.mapContainerClassName}
        clickableIcons={googleConfig.clickableIcons}
        onLoad={googleConfig.onLoad}
        onTilesLoaded={googleConfig.onTilesLoaded}
        options={googleConfig.options}
        ref={googleConfig.ref}>
        children
      </GoogleMap>
    </LoadScript>;
  | (MapMod.MMI, MapMod.MMI(_scriptUrl))  => React.null
  | (_, _) => React.null
  };
};