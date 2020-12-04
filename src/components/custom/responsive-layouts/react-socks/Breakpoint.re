module Provider = {
  [@bs.module "react-socks"] [@react.component]
  external make: (~children: React.element) => React.element = "BreakpointProvider";
};

[@bs.module "react-socks"] [@react.component]
external make:
  (
    ~only: option(bool)=?,
    ~up: option(bool)=?,
    ~down: option(bool)=?,
    ~xsmall: option(bool)=?,
    ~small: option(bool)=?,
    ~medium: option(bool)=?,
    ~large: option(bool)=?,
    ~xlarge: option(bool)=?,
    ~children: React.element,
    ~customQuery: option(string)=?
  ) =>
  React.element =
  "Breakpoint";

/*
   COMBINATIONS OF PROPS TO USE

    mobile & tablet => medium=true down=true
    laptop & abvove => large=true, up=true
 */
