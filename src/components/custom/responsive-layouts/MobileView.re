[@react.component]
let make = (~children: React.element) => {
  <Breakpoint medium=true down=true> children </Breakpoint>;
};
