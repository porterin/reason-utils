let createMarkerOptsForDivIcon =
    (marker: Marker.divMarkerOptions): Marker.options => {
  Marker.
    {
      icon: MmiMarkerBinding.setDivIcon(marker.divIcon),
      title: marker.icon_label,
      zIndexOffset: marker.z_index_offset,
      riseOnHover: marker.rise_on_hover,
      riseOffset: marker.rise_offset,
    };
};
