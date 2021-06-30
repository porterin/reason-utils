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
  helper_text: CommonTypes.viewText,
  className: string,
  error: bool,
  _inputProps: option(_inputProps),
};

let make_props =
    (
      ~label: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~isDisabled: bool=false,
      ~placeholder="",
      ~onBlur: unit => unit=() => (),
      ~result: option(Belt.Result.t('b, 'c)),
      ~warning=_ => None,
      ~className="",
      ~helper_text: CommonTypes.viewText=NoText,
      ~error=false,
      ~_inputProps: option(_inputProps)=?,
      (),
    )
    : t('b, 'c) => {
  label,
  id,
  onChange,
  isDisabled,
  placeholder,
  onBlur,
  result,
  warning,
  helper_text,
  className,
  error,
  _inputProps,
};
