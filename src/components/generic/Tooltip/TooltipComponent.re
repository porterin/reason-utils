type placement =
  | Bottom
  | Bottom_End
  | Bottom_Start
  | Left
  | Left_End
  | Left_Start
  | Right
  | Right_End
  | Right_Start
  | Top
  | Top_End
  | Top_Start;

let mapPlacement = (placement: placement): MaterialUi_Tooltip.placement => {
  switch placement {
  | Bottom => `Bottom
  | Bottom_End => `Bottom_End
  | Bottom_Start => `Bottom_Start
  | Left => `Left
  | Left_End => `Left_End
  | Left_Start => `Left_Start
  | Right => `Right
  | Right_End => `Right_End
  | Right_Start => `Right_Start
  | Top => `Top
  | Top_End => `Top_End
  | Top_Start => `Top_Start
  };
};

[@react.component]
let make =
    (
      ~content: string,
      ~placement: placement=Bottom,
      ~className: string="",
      ~children,
    ) => {
  <MaterialUi_Tooltip
    arrow=true
    title={React.string(content)}
    placement={placement |> mapPlacement}
    classes={MaterialUi_Tooltip.Classes.make(
      ~tooltip="tooltip " ++ className,
      ~arrow="tooltip-arrow",
      (),
    )}
    interactive=true>
    children
  </MaterialUi_Tooltip>;
};
