module ReactDependentScript = {
  [@bs.module "react-dependent-script"] [@react.component]
  external make:
    (
      ~loadingComponent: React.element,
      ~scripts: array(string),
      ~renderChildren: unit => React.element
    ) =>
    React.element =
    "default";
};

[@react.component]
let make =
    (
      ~scripts: array(string),
      ~children: React.element,
      ~loaderclassName="",
      ~errorclassName="",
      ~timeout=5000,
    ) => {
  let (isError, setIsError) = React.useState(_ => false);

  <ReactDependentScript
    loadingComponent={
      switch (isError) {
      | false =>
        let _timeoutId =
          Js.Global.setTimeout(() => setIsError(_ => true), timeout);
        <CircularLoader className=loaderclassName />;
      | true => {
        Js.log("Map load fail");
        <ErrorDisplayComponent
          error={ErrorUtils.getDefaultErrorEntity(
            ~message="The component failed to load",
            (),
          )}
          className=errorclassName
        />
        }
      }
    }
    scripts
    renderChildren={() => children}
  />;
};
