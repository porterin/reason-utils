module TestComponents = {
  [@react.component]
  let make = () => {
    <div> <ExampleDateConversion /> </div>;
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
