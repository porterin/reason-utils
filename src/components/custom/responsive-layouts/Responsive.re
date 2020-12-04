[@react.component]
let make = (~children: React.element) => {
  <Breakpoint.Provider> children </Breakpoint.Provider>;
};
