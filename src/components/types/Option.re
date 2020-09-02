type t = {
  id: string,
  label: string,
  value: string,
};

let toSelectOption = (options: list(t)) => {
  options
  |> List.map((option: t) =>
       SelectComponent.{key: option.id, value: option.value, text: option.label}
     );
};

let fromSelectOption = (option: SelectComponent.t) => {
  {id: option.key, value: option.value, label: option.text};
};
