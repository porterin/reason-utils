open Belt;

[@react.component]
let make =
    (
      ~content: React.element,
      ~anchor_el: option(Dom.element),
      ~onClose: unit => unit,
      ~horizontal_position: MaterialUi_Popover.horizontal_enum=`Left,
      ~vertical_position: MaterialUi_Popover.vertical_enum=`Bottom,
      ~horizontal_transform: MaterialUi_Popover.horizontal_enum=`Center,
      ~vertical_transform: MaterialUi_Popover.vertical_enum=`Top,
      ~className: option(string)=?,
    ) => {
  let position =
    MaterialUi_Popover.AnchorOrigin.make(
      ~horizontal=`Enum(horizontal_position),
      ~vertical=`Enum(vertical_position),
    );

  let transform =
    MaterialUi_Popover.TransformOrigin.make(
      ~horizontal=`Enum(horizontal_transform),
      ~vertical=`Enum(vertical_transform),
    );

  MaterialUi.(
    <Popover
      anchorOrigin=position
      transformOrigin=transform
      open_={Option.isSome(anchor_el)}
      onClose={_evt => onClose()}
      anchorEl=?{anchor_el->(Option.map(el => `ObjectGeneric(el->ReactDOMRe.domElementToObj)))}
      className={Option.getWithDefault(className, "")}>
      <div className="popover-content"> content </div>
    </Popover>
  );
};
