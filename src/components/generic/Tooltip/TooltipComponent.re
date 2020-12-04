[@react.component]
let make =
    (
      ~content: string,
      ~placement: MaterialUi_Tooltip.placement=`Bottom,
      ~className: string="",
      ~children
    ) => {
  <MaterialUi_Tooltip
    arrow=true
    title=React.string(content)
    placement
    classes=[Tooltip("tooltip " ++ className), Arrow("tooltip-arrow")]
    interactive=true>
    children
  </MaterialUi_Tooltip>;
};
