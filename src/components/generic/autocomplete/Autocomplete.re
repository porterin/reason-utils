type optionLabel = {
  label: string
};
[@react.component]
let make = (~id:string, ~options:array(optionLabel), ~label:string) => {
  <MaterialUi_Lab.Autocomplete
        id
        options = {options->Belt.Array.map(v => v->MaterialUi.Any)}
        getOptionLabel = {option => option.label}
        renderInput={params =>
            React.createElement(
            MaterialUi.TextField.make,
            Js.Obj.assign(
                params->Obj.magic,
                {"label": label, "variant": "outlined"},
            ),
            )
        }
  />;
};