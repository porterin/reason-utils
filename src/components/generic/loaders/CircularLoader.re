/* TO BE Deprecated */
[@react.component]
let make = (~className="") => {
  <div className style={ReactDOMRe.Style.make(~marginTop="10rem", ~marginLeft="50%", ())}>
    <MaterialUi.CircularProgress />
  </div>;
};
