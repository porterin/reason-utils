module Zoom = {
  [@bs.module "react-reveal/Zoom"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Fade = {
  [@bs.module "react-reveal/Fade"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Slide = {
  [@bs.module "react-reveal/Slide"] [@react.component]
  external make: (~left: bool, ~children: React.element) => React.element = "default";
};

module ReactSpring = {
  [@react.component]
  let make = () => {
    <Slide.make left={true}> <div> {React.string("I will Zoom")} </div> </Slide.make>;
  };
};

%bs.raw
{|require(`./_trans.scss`)|};

[@react.component]
let make = () => {
  <ReactSpring
    /* <div className="parent"> <div className="child"> {React.string("I am a div")} </div> </div>; */
  />;
};
