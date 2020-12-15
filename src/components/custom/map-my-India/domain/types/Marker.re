type options = {
  icon: MmiBaseType.icon,
  title: option(string),
  zIndexOffset: option(int),
  riseOnHover: option(bool),
  riseOffset: option(int),
};
type markerProps = {
  location: LatLng.t,
  marker_options: option(options),
};

type divMarkerOptions = {
  icon_classname: option(string),
  icon_label: option(string),
  z_index_offset: option(int),
  rise_on_hover: option(bool),
  rise_offset: option(int),
  divIcon: DivIcon.t,
};

type imgIconOpts = {
  iconUrl: string,
  iconSize: option(array(int)),
  iconAnchor: option(array(int)),
  popupAnchor: option(array(int)),
  shadowUrl: option(string),
  shadowSize: option(array(int)),
  shadowAnchor: option(array(int)),
};

let toDivMarkerOptions =
    (
      iconOptions: DivIcon.options,
      iconAnchor: array(int),
      popupAnchor: array(int),
    )
    : divMarkerOptions => {
  icon_classname: iconOptions.icon_classname,
  icon_label: iconOptions.icon_label,
  z_index_offset: iconOptions.z_index_offset,
  rise_on_hover: iconOptions.rise_on_hover,
  rise_offset: iconOptions.rise_offset,
  divIcon: {
    html: iconOptions.icon |> ReactDOMServerRe.renderToString,
    iconAnchor,
    popupAnchor,
  },
};
