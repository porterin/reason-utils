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
  };

  let make_props =
      (
        ~value: option(SelectComponent.t),
        ~items: list(SelectComponent.t),
        ~isNoneRequired: bool,
      )
      : t => {
    value,
    items,
    isNoneRequired,
  };
};

module SelectUtils = {
  let getSelectComponentItem =
      (typeItem: option('a), conv: 'a => string): option(SelectComponent.t) => {
    Belt.Option.flatMap(
      typeItem,
      item => {
        let typeString = item->conv;
        Some(
          {
            key: Js.String.toLowerCase(typeString),
            value: typeString,
            text: typeString |> Js.String.toUpperCase,
          }: SelectComponent.t,
        );
      },
    );
  };

  let getTypeItems = (typeList: list('a), conv: 'a => string): list(SelectComponent.t) => {
    typeList
    |> List.map((variant) =>
         (
           {
             let typeString = variant->conv;
             {
               key: Js.String.toLowerCase(typeString),
               value: typeString,
               text: typeString |> Js.String.toUpperCase,
             };
           }: SelectComponent.t
         )
       );
  };
};

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~select_props: SelectProps.t) => {
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
