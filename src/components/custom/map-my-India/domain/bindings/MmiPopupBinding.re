[@bs.scope "L"] [@bs.new] external createPopup: Popup.options => MmiBaseType.popup = "popup";

[@bs.send]
external bindPopup: (MmiBaseType.marker, string, ~opt: Popup.options=?, unit) => MmiBaseType.marker =
  "bindPopup";

[@bs.send] external unbindPopup: (MmiBaseType.marker, unit) => MmiBaseType.marker = "unbindPopup";

[@bs.send] external isPopupOpen: MmiBaseType.marker => bool = "isPopupOpen";

[@bs.send] external openPopup: MmiBaseType.marker => MmiBaseType.marker = "openPopup";

[@bs.send] external closePopup: MmiBaseType.marker => MmiBaseType.marker = "closePopup";
