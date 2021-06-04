// let getGoogleConfig = (config: PopupMod.config): GoogleInfoWindow.config => {
//   position: config.position,
//   options:
//     switch (config.anchor) {
//     | Some(anchorPoints) =>
//       Some({
//         pixelOffset: {
//           width: anchorPoints[0],
//           height: anchorPoints[1],
//         },
//       })
//     | None => None
//     },
//   onCloseClick: config.onCloseClick,
//   ref: config.ref,
// };
// [@react.component]
// let make =
//     (~lib_name: MapMod.lib=MapMod.GoogleMap, ~config: PopupMod.config, ~children: React.element) => {
//   switch (lib_name) {
//   | MapMod.GoogleMap =>
//     let googleConfig = getGoogleConfig(config);
//     switch (googleConfig.position, googleConfig.options) {
//     | (Some(pos), Some(opts)) =>
//       <GoogleInfoWindow
//         position=pos
//         onCloseClick={googleConfig.onCloseClick->Belt.Option.getWithDefault(() => ())}
//         options=opts
//         ref={googleConfig.ref}>
//         children
//       </GoogleInfoWindow>
//     | (_, _) =>
//       <GoogleInfoWindow
//         onCloseClick={googleConfig.onCloseClick->Belt.Option.getWithDefault(() => ())}
//         ref={googleConfig.ref}>
//         children
//       </GoogleInfoWindow>
//     };
//   | MapMod.MMI => React.null
//   };
// };
