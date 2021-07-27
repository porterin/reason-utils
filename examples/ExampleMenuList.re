[@react.component]
let make = () => {
  let list = ["Item 1", "Item 2"];

  let menuActions: list(MenuList.menu_item) =
    list
    |> List.map(menu => {
         let menuString = menu;
         Catalyst.MenuList.{item_label: Text(menuString), item_cb: () => ()};
       });

  <MenuList menuButtonTitle="" postfixIcon=Hamburger menuItems=menuActions />;
};
