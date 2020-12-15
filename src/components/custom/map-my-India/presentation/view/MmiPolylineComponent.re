type state = {mmiPolyline: option(MmiBaseType.polyline)};

type actions =
  | DrawPolyline(option(MmiBaseType.polyline));

let reducer = (_state: state, action: actions) =>
  switch (action) {
  | DrawPolyline(mmiPolyline) => {mmiPolyline: mmiPolyline}
  };

[@react.component]
let make =
    (
      ~map: MmiBaseType.map,
      ~polylineOptions: Polyline.polylineOptions,
      ~route_coordinates: array(LatLng.t),
      ~children,
    ) => {
  let initialState = {mmiPolyline: None};
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let polylineOpts: Polyline.options = {
    color: Belt.Option.getWithDefault(polylineOptions.color, "#3388ff"),
    weight: Belt.Option.getWithDefault(polylineOptions.weight, 3),
    opacity: Belt.Option.getWithDefault(polylineOptions.opacity, 1.0),
  };

  React.useEffect0(() => {
    let mmiPolyline =
      MmiPolylineBinding.createPolyline(
        ~pos=route_coordinates,
        ~opt=polylineOpts,
        (),
      );
    dispatch(DrawPolyline(Some(mmiPolyline)));
    Some(
      () =>
        MmiPolylineBinding.removePolylineFromMap(mmiPolyline, map) |> ignore,
    );
  });

  React.useEffect1(
    () => {
      switch (state.mmiPolyline) {
      | Some(mmiPolyline) =>
        MmiPolylineBinding.addPolylineToMap(mmiPolyline, map) |> ignore
      | _ => ()
      };
      None;
    },
    [|state.mmiPolyline|],
  );

  <>
    {switch (state.mmiPolyline) {
     | Some(_polyline) => children
     | None => React.null
     }}
  </>;
};
