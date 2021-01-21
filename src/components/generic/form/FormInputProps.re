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
  warning: ReactEvent.Form.t => option(string),
  className: string,
  _inputProps: option(_inputProps),
};
