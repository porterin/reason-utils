type t = {
  selected: list(string),
  options: list(SelectWithCheckBoxes.t),
  renderValue: option(list(string) => string),
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~select_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <SelectWithCheckBoxes
      label={input_props.label}
      selected={select_props.selected}
      onChange={input_props.onChange}
      items={select_props.options}
      renderValue={select_props.renderValue}
      placeholder={input_props.placeholder}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result, input_props.helper_text)}
  </FormInputWrapper>;
};
