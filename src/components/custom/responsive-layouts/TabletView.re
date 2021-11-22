[@react.component]
let make = (~children: React.element) => {
  <Breakpoint customQuery="(min-width: 577px) and (max-width: 991px)"> children </Breakpoint>;
};
