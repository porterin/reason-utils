external toDomElement: 'a => Dom.element = "%identity";

[@react.component]
let make = () => {
  let (popoverState, togglePopover) = PopoverStateManager.usePopover();
  <>
    <div
      className="popover-content"
      onClick={evt =>
        togglePopover(_ =>
          {
            anchor_el: Some(evt->ReactEvent.Mouse.target->toDomElement),
            view: <div> {React.string("Some Text")} </div>,
          }
        )
      }>
      {React.string("Popover")}
    </div>
    <PopoverComponent
      content={popoverState.view}
      onClose={_ => togglePopover(_ => {...popoverState, anchor_el: None})}
      anchor_el={popoverState.anchor_el}
    />
  </>;
};
