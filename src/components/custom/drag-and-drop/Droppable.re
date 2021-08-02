type draggableId = string;
type droppableId = string;

type droppableProvidedProps = {
  [@bs.as "data-rbd-droppable-context-id"]
  contextId: string,
  [@bs.as "data-rbd-droppable-id"]
  droppableId,
};

let droppableProvidedPropsToJs = (p: droppableProvidedProps, ref_: ReactDOMRe.domRef) => {
  {
    "data-rbd-droppable-context-id": p.contextId,
    "data-rbd-droppable-id": p.droppableId,
    "ref": ref_,
  };
};

type droppableProvided = {
  innerRef: React.ref(Js.Nullable.t(Dom.element)),
  placeholder: option(React.element),
  droppableProps: droppableProvidedProps,
};

type droppableStateSnapshot = {
  isDraggingOver: bool,
  draggingOverWith: option(draggableId),
  draggingFromThisWith: option(draggableId),
  isUsingPlaceholder: option(bool),
};

[@bs.module "react-beautiful-dnd"] [@react.component]
external make:
  (
    ~droppableId: droppableId,
    ~direction: option(string)=?,
    ~children: (droppableProvided, droppableStateSnapshot) => React.element
  ) =>
  React.element =
  "Droppable";
