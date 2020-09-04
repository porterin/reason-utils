type t =
  | Primary
  | Secondary;

type buttonProps = {
  label: ButtonLabel.t,
  disabled: bool,
  onSelectCB: ReactEvent.Mouse.t => unit,
  buttonType: t,
  prefixIcon: React.element,
  postfixIcon: React.element,
  size: MaterialUi.Fab.size,
  className: string,
};
