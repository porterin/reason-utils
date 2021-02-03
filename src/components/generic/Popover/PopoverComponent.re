open Belt;

type horizontal_position =
  | Center
  | Left
  | Right;

type vertical_position =
  | Center
  | Top
  | Bottom;

let mapHorizontal = (pos: horizontal_position): MaterialUi_Popover.Horizontal_enum.t => {
  switch (pos) {
  | Center => MaterialUi_Popover.Horizontal_enum.center
  | Left => MaterialUi_Popover.Horizontal_enum.left
  | Right => MaterialUi_Popover.Horizontal_enum.right
  };
};

let mapVertical = (pos: vertical_position): MaterialUi_Popover.Vertical_enum.t => {
  switch (pos) {
  | Center => MaterialUi_Popover.Vertical_enum.center
  | Top => MaterialUi_Popover.Vertical_enum.top
  | Bottom => MaterialUi_Popover.Vertical_enum.bottom
  };
};

[@react.component]
let make =
    (
      ~content: React.element,
      ~anchor_el: option(Dom.element),
      ~onClose: unit => unit,
      ~horizontal_position: horizontal_position=Center,
      ~vertical_position: vertical_position=Bottom,
      ~horizontal_transform: horizontal_position=Center,
      ~vertical_transform: vertical_position=Top,
      ~className: option(string)=?,
    ) => {
  let position =
    MaterialUi_Popover.AnchorOrigin.make(
      ~horizontal=horizontal_position->mapHorizontal->MaterialUi_Popover.Horizontal.enum,
      ~vertical=vertical_position->mapVertical->MaterialUi_Popover.Vertical.enum,
      (),
    );

  let transform =
    MaterialUi_Popover.TransformOrigin.make(
      ~horizontal=horizontal_transform->mapHorizontal->MaterialUi_Popover.Horizontal.enum,
      ~vertical=vertical_transform->mapVertical->MaterialUi_Popover.Vertical.enum,
      (),
    );

  MaterialUi.(
    <Popover
      anchorOrigin=position
      transformOrigin=transform
      _open={Option.isSome(anchor_el)}
      onClose={_evt => onClose()}
      anchorEl=?{
        anchor_el->(
                     Option.map(el =>
                       MaterialUi.Popover.AnchorEl.obj(el->ReactDOMRe.domElementToObj)
                     )
                   )
      }
      className={Option.getWithDefault(className, "")}>
      <div className="popover-content"> content </div>
    </Popover>
  );
};
