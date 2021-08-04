type load_config = {
    googleMapsApiKey: string,
    libraries: array(string),
  };
  
  [@bs.module "@react-google-maps/api"] [@react.component]
  external make:
    (
      ~googleMapsApiKey: string,
      ~id: string,
      ~libraries: array(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~loadingElement: React.element=?,
      ~children: React.element
    ) =>
    React.element =
    "LoadScript";
  