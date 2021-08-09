[@react.component]
let make = (~children: React.element) => {
  <Breakpoint customQuery="(min-width: 576px) and (max-width: 992px)"> children </Breakpoint>;
};
