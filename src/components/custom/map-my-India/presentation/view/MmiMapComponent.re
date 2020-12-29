type state = {mmiMap: option(MmiBaseType.map)};

type actions =
  | SetMyMap(option(MmiBaseType.map));

let reducer = (_state: state, action: actions) => {
  switch (action) {
  | SetMyMap(mmiMap) => {mmiMap: mmiMap}
  };
};

[@react.component]
let make = (~mapOptions: MmiMap.mapOptions, ~children: _ => React.element) => {
  let initialState = {mmiMap: None};
  let centerLoc = mapOptions.center;
  let mapOpts: MmiMap.options = {
    center: centerLoc,
    zoomControl: Some(mapOptions.zoom_control),
    hybrid: Some(mapOptions.hybrid),
  };

  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let mmiMap = MmiMapBinding.createMap(mapOptions.map_elem_id, mapOpts);
    dispatch(SetMyMap(Some(mmiMap)));
    None;
  });
  <>
    <div className="track-order-map__container">
      <div
        id={mapOptions.map_elem_id}
        className="track-order-map__canvas"
        ref={ReactDOMRe.Ref.domRef(React.useRef(Js.Nullable.null))}
      />
    </div>
    {switch (state.mmiMap) {
     | Some(mmiMap) => children(mmiMap)
     | None => React.null
     }}
    <div />
  </>;
};
