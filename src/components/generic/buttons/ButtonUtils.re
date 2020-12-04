open ButtonTypes;

let getDefaultButtonProps =
    (
      ~label: ButtonLabel.t,
      ~disabled: bool=false,
      ~onSelectCB: ReactEvent.Mouse.t => unit=_ => (),
      ~buttonType: t=Primary,
      ~prefixIcon: React.element=React.null,
      ~postfixIcon: React.element=React.null,
      ~size: MaterialUi.Fab.size=`Small,
      ~className: string="",
      (),
    )
    : buttonProps => {
  label,
  onSelectCB,
  prefixIcon,
  postfixIcon,
  buttonType,
  size,
  className,
  disabled,
};
