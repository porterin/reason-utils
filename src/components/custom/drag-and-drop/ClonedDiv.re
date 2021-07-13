[@react.component]
let make = (~props: Js.t('a), ~children: React.element) => {
  ReasonReact.cloneElement(<div />, ~props, [|children|]);
};
