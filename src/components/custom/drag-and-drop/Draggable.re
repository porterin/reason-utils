type draggableId = string;
type droppableId = string;

type dragingStyle = {
  position: string,
  top: int,
  left: int,
  boxSizing: string,
  width: int,
  height: int,
  transition: string,
  transform: option(string),
  zIndex: int,
  opacity: option(int),
  pointerEvents: string,
};

type draggableProvidedDraggableProps = {
  style: dragingStyle,
  [@bs.as "data-rbd-draggable-context-id"]
  contextId: string,
  [@bs.as "data-rbd-draggable-id"]
  draggableId: string,
  onTransitionEnd: option(ReactEvent.Transition.t => unit),
};

type draggableProvidedDragHandleProps = {
  [@bs.as "data-rbd-drag-handle-draggable-id"]
  draggableId,
  [@bs.as "data-rbd-drag-handle-context-id"]
  contextId: string,
  [@bs.as "aria-describedby"]
  ariaDescribedby: string,
  role: string,
  tabIndex: int,
  draggable: bool,
  onDragStart: option(ReactEvent.Transition.t),
};

let draggablePropsToJs =
    (d: draggableProvidedDraggableProps, ref_: ReactDOMRe.domRef) => {
      
  {
    "data-rbd-draggable-context-id": d.contextId,
    "style": d.style,
    "data-rbd-draggable-id": d.draggableId,
    "onTransitionEnd": d.onTransitionEnd,
    "ref": ref_,
  };
};

let dragHandlePropsToJs =
    (p: option(draggableProvidedDragHandleProps)) => {
  switch (p) {
  | None => {
      "data-rbd-drag-handle-draggable-id": "",
      "data-rbd-drag-handle-context-id": "",
      "aria-describedby": "",
      "role": "",
      "tabIndex": 0,
      "draggable": false,
      "onDragStart": None
    }
  | Some(l) => {
      "data-rbd-drag-handle-draggable-id": l.draggableId,
      "data-rbd-drag-handle-context-id": l.contextId,
      "aria-describedby": l.ariaDescribedby,
      "role": l.role,
      "tabIndex": l.tabIndex,
      "draggable": l.draggable,
      "onDragStart": l.onDragStart
    }
  };
};

type draggableProvided = {
  innerRef: React.ref(Js.Nullable.t(Dom.element)),
  draggableProps: draggableProvidedDraggableProps,
  dragHandleProps: option(draggableProvidedDragHandleProps),
};

type draggableStateSnapshot = {
  isDragging: bool,
  isDropAnimating: bool,
};

type draggableLocation = {
  droppableId,
  index: int,
};

type draggableRubric = {
  draggableId,
  source: draggableLocation,
};

[@bs.module "react-beautiful-dnd"] [@react.component]
external make:
  (
    ~draggableId: draggableId,
    ~index: int,
    ~children: (draggableProvided, draggableStateSnapshot, draggableRubric) =>
               React.element,
    ~isDragDisabled: option(bool)=?,
    ~disableInteractiveElementBlocking: option(bool)=?,
    ~shouldRespectForcePress: option(bool)=?
  ) =>
  React.element =
  "Draggable";
