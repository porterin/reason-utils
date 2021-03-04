type t = {
  selected: list(string),
  options: list(CheckBoxGroup.t),
  row_layout: bool,
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~checkbox_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <CheckBoxGroup
      label={input_props.label}
      selected={checkbox_props.selected}
      onChange={input_props.onChange}
      options={checkbox_props.options}
      row_layout={checkbox_props.row_layout}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
