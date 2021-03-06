type t = {
  value: string,
  _type: string,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~textinput_props: t) => {
  let (warning, setWarning) = React.useState(_ => None);
  <FormInputWrapper className={input_props.className}>
    <MaterialUi.TextField
      label={React.string(input_props.label)}
      margin=`Dense
      size=`Medium
      value={MaterialUi.TextField.Value.string(textinput_props.value)}
      onBlur={_ => input_props.onBlur()}
      disabled={input_props.isDisabled}
      _type={textinput_props._type}
      onChange={event => {
        ReactEvent.Form.persist(event);
        setWarning(_ => input_props.warning(event));
        input_props.onChange(event);
      }}
      placeholder={input_props.placeholder}
      variant=`Outlined
      className="form-input"
      _InputLabelProps={"className": "form-input-label"}
      _InputProps={FormInputHelper.get_InputProps(input_props._inputProps)}
    />
    {FormInputHelper.getWarningOrError(warning, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};

