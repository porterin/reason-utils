type t = {
  value: option(SelectComponent.t),
  items: list(SelectComponent.t),
  isNoneRequired: bool,
};

module SelectProps = {
  type t = {
    value: option(SelectComponent.t),
    items: list(SelectComponent.t),
    isNoneRequired: bool,
    onClose: unit => unit,
    onOpen: unit => unit
  };

  let make_props =
      (
        ~value: option(SelectComponent.t),
        ~items: list(SelectComponent.t),
        ~onClose: unit=>unit=()=>(),
        ~onOpen: unit=>unit=()=>(),
        ~isNoneRequired: bool,
      )
      : t => {
    value,
    items,
    isNoneRequired,
    onClose,
    onOpen
  };
};

[@react.component]
let make =
    (~input_props: FormInputProps.t('b, 'c), ~select_props: SelectProps.t) => {
  <FormInputWrapper className={input_props.className}>
    <SelectComponent
      label={input_props.label}
      value={select_props.value}
      onChange={input_props.onChange}
      items={select_props.items}
      isNoneRequired={select_props.isNoneRequired}
      onBlur={input_props.onBlur}
      onClose={select_props.onClose}
      onOpen={select_props.onOpen}
    />
    {FormInputHelper.getWarningOrError(None, input_props.result)}
  </FormInputWrapper>;
};
