type menu_item = {
  item_label: ButtonLabel.t,
  item_cb: unit => unit,
};

external toDomElement: 'a => Dom.element = "%identity";

let buildMenuList =
    (
      ~menuItems: list(menu_item),
      ~togglePopover: (PopoverStateManager.config => PopoverStateManager.config) => unit,
    ) => {
  <MaterialUi.MenuList className="menu-list">
    {menuItems
     |> List.map(item =>
          <MaterialUi.MenuItem
            className="menu-item"
            onClick={_ => {
              togglePopover(_ => {view: React.null, anchor_el: None});
              item.item_cb();
            }}>
            <ButtonLabelDecorator label={item.item_label}> {label => label} </ButtonLabelDecorator>
          </MaterialUi.MenuItem>
        )
     |> ReasonReactUtils.listToReactArray}
  </MaterialUi.MenuList>;
};

[@react.component]
let make =
    (~iconContent: _ => React.element, ~_caret: bool=true, ~menuItems: list(menu_item))
    : React.element => {
  let (popoverState, togglePopover) = PopoverStateManager.usePopover();
  <>
    <PrimaryButton
      buttonProps={ButtonUtils.getDefaultButtonProps(
        ~label=Custom(iconContent),
        ~className="hamburger-button",
        ~onSelectCB=
          (event: ReactEvent.Mouse.t) =>
            togglePopover(_ =>
              {
                anchor_el: Some(event->ReactEvent.Mouse.target->toDomElement),
                view: buildMenuList(~menuItems, ~togglePopover),
              }
            ),
        (),
      )}
    />
    <PopoverComponent
      className="menulist-container-v2"
      content={popoverState.view}
      onClose={_ => togglePopover(_ => {...popoverState, anchor_el: None})}
      anchor_el={popoverState.anchor_el}
      horizontal_position=Right
      vertical_position=Bottom
      horizontal_transform=Right
      vertical_transform=Top
    />
  </>;
};
