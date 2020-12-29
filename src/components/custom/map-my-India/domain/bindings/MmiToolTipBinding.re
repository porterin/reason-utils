[@bs.scope "L"] [@bs.new]
external createToolTip: Tooltip.options => MmiBaseType.toolTip = "tooltip";

[@bs.send] external openTooltip: MmiBaseType.marker => MmiBaseType.marker = "openTooltip";

[@bs.send]
external bindToolTip:
  (MmiBaseType.marker, string, ~opt: Tooltip.options=?, unit) => MmiBaseType.marker =
  "bindTooltip";

[@bs.send] external closeTooltip: MmiBaseType.marker => MmiBaseType.marker = "closeTooltip";

[@bs.send]
external unBindToolTip: (MmiBaseType.marker, unit) => MmiBaseType.marker = "unbindTooltip";
