[@react.component]
let make = (~children: React.element) => {
  <Breakpoint small=true down=true> children </Breakpoint>;
};
