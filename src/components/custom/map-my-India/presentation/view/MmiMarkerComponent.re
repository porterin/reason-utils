type state = {marker: option(MmiBaseType.marker)};

type actions =
  | SetMyMarker(option(MmiBaseType.marker));

let reducer = (_state: state, action: actions) => {
  switch (action) {
  | SetMyMarker(marker) => {marker: marker}
  };
};

[@react.component]
let make =
    (~map: MmiBaseType.map, ~marker_props: Marker.markerProps, ~children) => {
  let initialState = {marker: None};
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let marker =
      MmiMarkerBinding.createMarker(
        ~pos=marker_props.location,
        ~opts=marker_props.marker_options,
        (),
      );
    MmiMarkerBinding.addMarkerToMap(marker, map) |> ignore;
    dispatch(SetMyMarker(Some(marker)));
    Some(() => MmiMarkerBinding.removeMarkerFromMap(marker, map)->ignore);
  });
  React.useEffect1(
    () => {
      switch (state.marker) {
      | Some(marker) =>
        MmiMarkerBinding.setMarkerLatLng(marker, marker_props.location)
        |> ignore
      | _ => ()
      };
      None;
    },
    [|marker_props.location|],
  );
  <>
    {switch (state.marker) {
     | Some(marker) => children(marker)
     | None => React.null
     }}
  </>;
};
