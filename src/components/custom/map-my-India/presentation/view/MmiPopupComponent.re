[@react.component]
let make =
    (
      ~marker: MmiBaseType.marker,
      ~popupOptions: Popup.popupOptions,
      ~activateTooltip=true,
      ~children,
    ) => {
  let (clicked, setClicked) = React.useState(() => false);
  let refClicked = React.useRef(clicked);
  React.useEffect1(
    () => {
      refClicked.current = clicked;
      None;
    },
    [|clicked|],
  );
  let popupOpts: Popup.options = {
    className: Belt.Option.getWithDefault(popupOptions.class_name, "pop-up"),
    closeButton: Belt.Option.getWithDefault(popupOptions.close_button, false),
    offset: Belt.Option.getWithDefault(popupOptions.offset, [|0, 0|]),
    closeOnClick: Belt.Option.getWithDefault(popupOptions.close_on_click, true),
  };

  let handleMouseOver = () => MmiPopupBinding.openPopup(marker) |> ignore;

  let handleMouseOut = () =>
    if (refClicked.current) {
      MmiPopupBinding.openPopup(marker) |> ignore;
    } else {
      MmiPopupBinding.closePopup(marker) |> ignore;
    };

  let handleClick = () => setClicked(_ => true);

  let handlePopupClosed = () => setClicked(_ => false);

  React.useEffect0(() => {
    if (activateTooltip) {
      MmiMarkerBinding.onMarker(marker, "mouseover", handleMouseOver) |> ignore;
      MmiMarkerBinding.onMarker(marker, "mouseout", handleMouseOut) |> ignore;
      MmiMarkerBinding.onMarker(marker, "preclick", handleClick) |> ignore;
      MmiMarkerBinding.onMarker(marker, "popupclose", handlePopupClosed) |> ignore;
    };
    None;
  });

  React.useEffect2(
    () => {
      MmiPopupBinding.bindPopup(
        marker,
        ReactDOMServerRe.renderToString(children),
        ~opt=popupOpts,
        (),
      )
      |> ignore;
      (
        if (activateTooltip) {
          MmiMarkerBinding.offMarker(marker, "click");
        }
      )
      |> ignore;
      None;
    },
    ([|marker|], children),
  );
  <> </>;
};
