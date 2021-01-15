let gtagExecCommand: string => unit = [%bs.raw
  {|
  function(measurement_id) {
     window.dataLayer = window.dataLayer || [];
    function gtag() {dataLayer.push(arguments);};
    gtag('js', new Date());
    gtag('config', measurement_id);
  }
|}
];


let useGaInitializer = (~load_ga_script: bool=false, ~debug: bool=false, ~measurement_id: string, ) => {
  let (state, setState) = React.useState(_ => React.null);

  let script_url = "https://www.googletagmanager.com/gtag/js?id=" ++ measurement_id;
  React.useEffect0(() => {
    let initializeOptions: GaInitializer.initializeOptions = {
      debug,
      titleCase: true,
      gaOptions: None,
    };
    ReactGaBindings.initialize(measurement_id, initializeOptions);
    setState(_ =>
      load_ga_script
        ? {
          gtagExecCommand(measurement_id);
          <ScriptFetcher scripts=[|script_url|]> React.null </ScriptFetcher>;
        }
        : React.null
    );
    None;
  });
  state;
};
