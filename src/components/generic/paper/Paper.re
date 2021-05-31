module Variant = {
  type t =
  | Elevated
  | Outlined;

  let toMuiVariant :(t) => MaterialUi_Paper.variant =
    fun
    | Elevated =>  `Elevation 
    | Outlined => `Outlined
};

[@react.component]
let make = (~elevation=0,  ~variant=Variant.Elevated, ~children=React.null) => {
    <MaterialUi_Paper 
        elevation=elevation->MaterialUi_Types.Number.int 
        variant=(variant -> Variant.toMuiVariant)>
        (children)
    </MaterialUi_Paper>
}