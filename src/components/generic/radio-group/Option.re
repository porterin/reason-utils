type t = {
  id: string,
  label: string,
  value: string,
};

let toSelectOption = (options: list(t)) => {
  options
  |> List.map((option: t) =>
       ({key: option.id, value: option.value, text: option.label}: SelectComponent.t)
     );
};

let fromSelectOption = (option: SelectComponent.t) => {
  {id: option.key, value: option.value, label: option.text};
};
