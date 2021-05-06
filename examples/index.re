module TestComponents = {
  [@react.component]
  let make = () => {
    <ExampleTransition/>
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
