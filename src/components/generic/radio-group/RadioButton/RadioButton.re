[@react.component]
let make = (
  ~id: string,
  ~value: string,
  ~onChange: option((ReactEvent.Form.t) => _),
  ~isSelected: bool
) => {
    <input 
      id=id
      value=value
      onChange=(switch(onChange) {
        | Some(onChange) => onChange
        | None => _ => ()
      })
      type_="radio"
      checked=isSelected
    />       
}