[@bs.module "react-ga"] [@bs.val]
external initialize: (string, GaInitializer.initializeOptions) => unit = "initialize";

[@bs.module "react-ga"] [@bs.val]
external pageview: (string, string) => unit = "pageview";

[@bs.module "react-ga"] [@bs.val]
external event: GaTrackingPayload.event => unit = "event";
