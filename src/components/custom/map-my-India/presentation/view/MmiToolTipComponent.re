[@react.component]
let make = (~marker: MmiBaseType.marker, ~toolTipOptions: Tooltip.toolTipOptions, ~children) => {
  let toolTipOpts: Tooltip.options = {
    class_name: Belt.Option.getWithDefault(toolTipOptions.class_name, ""),
    sticky: Belt.Option.getWithDefault(toolTipOptions.sticky, false),
    offset: Belt.Option.getWithDefault(toolTipOptions.offset, [|0, 0|]),
  };

  React.useEffect2(
    () => {
      MmiToolTipBinding.bindToolTip(
        marker,
        ReactDOMServerRe.renderToString(children),
        ~opt=toolTipOpts,
        (),
      )
      |> ignore;
      None;
    },
    ([|marker|], children),
  );
  <> </>;
};
