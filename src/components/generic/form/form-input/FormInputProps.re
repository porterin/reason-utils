type _inputProps = {
  className: string,
  startAdornment: React.element,
};

type t('b, 'c) = {
  label: string,
  onChange: ReactEvent.Form.t => unit,
  isDisabled: bool,
  placeholder: string,
  result: option(Belt.Result.t('b, 'c)),
  onBlur: unit => unit,
  onClose: unit => unit,
  onOpen: unit => unit,
  warning: ReactEvent.Form.t => option(string),
  className: string,
  _inputProps: option(_inputProps),
};

let make_props =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~isDisabled: bool=false,
      ~placeholder="",
      ~onBlur: unit => unit=() => (),
      ~onClose: unit => unit=() => (),
      ~onOpen: unit => unit=() => (),
      ~result: option(Belt.Result.t('b, 'c)),
      ~warning=_ => None,
      ~className="",
      ~_inputProps: option(_inputProps)=?,
      (),
    )
    : t('b, 'c) => {
  label,
  onChange,
  isDisabled,
  placeholder,
  onBlur,
  onClose,
  onOpen,
  result,
  warning,
  className,
  _inputProps,
};
