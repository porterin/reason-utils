type state = {component: ReasonReact.reactElement};

type action =
  | LoadIFrame(ReasonReact.reactElement);

let getInitialState = (): state => {component: <div> {React.string("Loading")} </div>};
[@react.component]
let make = (~url, ~iframe_class_name: string="") => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | LoadIFrame(dataToRender) => {component: dataToRender}
        },
      getInitialState(),
    );

  React.useEffect0(() => {
    dispatch(
      LoadIFrame(
        <iframe src=url className={"iframe " ++ iframe_class_name} allowFullScreen=true />,
      ),
    );
    None;
  });
  <div className="iframe-wrapper" id="iframeId"> {state.component} </div>;
};
