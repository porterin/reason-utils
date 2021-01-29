type t = {
  options: list(RadioButtonGroup.t),
  value: string,
  row_layout: bool,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~radio_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <RadioButtonGroup
      label={input_props.label}
      options={radio_props.options}
      value={radio_props.value}
      onChange={input_props.onChange}
      row={radio_props.row_layout}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
