type draggableId = string;
type droppableId = string;

type draggableLocation = {
  droppableId,
  index: int,
};

type combine = {
  draggableId,
  droppableId,
};

type dropResult = {
  destination: option(draggableLocation),
  combine: option(combine),
  draggableId,
  source: draggableLocation,
};

type responderProvided = {announce: string => unit};

[@bs.module "react-beautiful-dnd"] [@react.component]
external make:
  (~onDragEnd: option((dropResult, responderProvided) => unit)=?, ~children: React.element) =>
  React.element =
  "DragDropContext";
