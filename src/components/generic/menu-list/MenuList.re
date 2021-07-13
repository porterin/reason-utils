type postfixIcon =
  | Caret
  | Hamburger
  | None;

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
    (
      ~menuButtonTitle: option(string)=?,
      ~className="",
      ~postfixIcon: postfixIcon=None,
      ~menuItems: list(menu_item),
      ~custom_menu_button: option(React.element)=?,
    )
    : React.element => {
  let (popoverState, togglePopover) = PopoverStateManager.usePopover();
  <>
    {switch (custom_menu_button) {
     | None =>
       <PrimaryButton
         buttonProps={ButtonUtils.getDefaultButtonProps(
           ~label=
             {menuButtonTitle->Belt.Option.mapWithDefault(
                ButtonLabel.(Custom(_ => React.null)), title =>
                Text(title)
              )},
           ~className,
           ~postfixIcon=
             {switch (postfixIcon) {
              | Caret => <Icon.ExpandMoreIcon />
              | Hamburger => <Icon.MoreVertIcon fontSize=`Large />
              | None => React.null
              }},
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
     | Some(ele) =>
       <div
         onClick={(event: ReactEvent.Mouse.t) =>
           togglePopover(_ =>
             {
               anchor_el: Some(event->ReactEvent.Mouse.target->toDomElement),
               view: buildMenuList(~menuItems, ~togglePopover),
             }
           )
         }>
         ele
       </div>
     }}
    <PopoverComponent
      className="menulist-container"
      content={popoverState.view}
      onClose={_ => togglePopover(_ => {...popoverState, anchor_el: None})}
      anchor_el={popoverState.anchor_el}
    />
  </>;
};
