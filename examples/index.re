[%bs.raw {|require(`../src/components/styles/main.scss`)|}];

module TestComponents = {
  [@react.component]
  let make = () => {
    <div> <ExampleFormInput /> </div>;
  };
};

ReactDOMRe.renderToElementWithId(<TestComponents />, "root");
