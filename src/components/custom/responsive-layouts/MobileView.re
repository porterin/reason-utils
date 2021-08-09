[@react.component]
let make = (~children: React.element) => {
  <Breakpoint customQuery="(max-width: 576px)"> children </Breakpoint>;
};
