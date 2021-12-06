[@bs.deriving jsConverter]
type position = [
  | [@bs.as "start"] `Start
  | [@bs.as "end"] `End
];
[@react.component]
let make =
    (
      ~position: position = `Start,
      ~className: string="",
      ~children: React.element,
    ) => {
  <MaterialUi.InputAdornment
    position={position}
    className={className}>
    children
  </MaterialUi.InputAdornment>;
};
