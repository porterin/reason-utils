[@react.component]
let make =
    (
      ~options: list(Option.t),
      ~onChange: option(ReactEvent.Form.t => _),
      ~defaultValue: option(string),
      ~className="u-margin-right-xs",
    ) => {
  options
  |> List.map((option: Option.t) => {
       <div id={option.id} className>
         <RadioButton
           id={option.id}
           value={option.value}
           onChange
           isSelected={
             switch (defaultValue) {
             | None => false
             | Some(default) => default == option.value
             }
           }
         />
         <label htmlFor={option.id}>
           {React.string(
              {
                option.label;
              },
            )}
         </label>
       </div>
     })
  |> Array.of_list |> React.array;
};
