type t = {
  value: option(SelectComponent.t),
  items: list(SelectComponent.t),
  isNoneRequired: bool
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~select_props: t) => {
  <FormInputWrapper className={input_props.className}>
    <SelectComponent
      label={input_props.label}
      value={select_props.value}
      onChange={input_props.onChange}
      items={select_props.items}
      isNoneRequired={select_props.isNoneRequired}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
