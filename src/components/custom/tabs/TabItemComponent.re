let onTabClick = (isActiveTab: bool, onTabSelectCB: _ => unit) =>
  if (!isActiveTab) {
    onTabSelectCB();
  } else {
    ();
  };

let getCloseBtn = (~tabIndex: int, ~label: string, ~onTabCloseCB: string => unit) => {
  tabIndex !== 0
    ? <span
        className="tab-item__close-btn"
        onClick={(event: ReactEvent.Mouse.t) => {
          onTabCloseCB(label);
          ReactEvent.Mouse.stopPropagation(event);
        }}>
        <Icon.CloseIcon fontSize=`Small />
      </span>
    : React.null;
};

[@react.component]
let make =
    (
      ~label: string,
      ~isActive: bool,
      ~onTabSelectCB: string => unit,
      ~onTabCloseCB: string => unit,
      ~tabIndex: int,
      ~tabOptions: list(MenuList.menu_item)=[],
    ) => {
  <div
    className={"tab-item" ++ (isActive ? " tab-item-active" : " tab-item-inactive")}
    onClick={_event => {onTabClick(isActive, _ => onTabSelectCB(label))}}>
    {React.string(label)}
    <div className="tab-actions-container">
      {switch (isActive, tabOptions) {
       | (false, _)
       | (true, []) => React.null
       | (true, menuItems) =>
         <MenuList postfixIcon=Caret className="custom-menu-button tab-menu-button" menuItems />
       }}
      {getCloseBtn(~tabIndex, ~label, ~onTabCloseCB)}
    </div>
  </div>;
};
