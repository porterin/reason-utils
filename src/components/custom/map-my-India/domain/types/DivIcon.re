type t = {
  html: string,
  iconAnchor: array(int),
  popupAnchor: array(int),
};

type options = {
  icon_classname: option(string),
  icon_label: option(string),
  z_index_offset: option(int),
  rise_on_hover: option(bool),
  rise_offset: option(int),
  icon: React.element,
};
