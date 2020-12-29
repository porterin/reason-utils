type navbar_item = {
  label: string,
  value: CommonTypes.viewText,
};

type navbar_action = {
  label: ButtonLabel.t,
  on_select_cb: unit => unit,
  icon: option(string),
};

let getActionButtons = (actions_list: list(navbar_action)) => {
  actions_list
  |> List.map((action_btn: navbar_action) =>
       <RoundedPrimaryButton
         buttonProps={ButtonUtils.getDefaultButtonProps(
           ~label=action_btn.label,
           ~onSelectCB=_ => action_btn.on_select_cb(),
           (),
         )}
       />
     );
};

[@react.component]
let make =
    (
      ~title: string,
      ~navbar_item_first: option(navbar_item)=?,
      ~navbar_item_second: option(navbar_item)=?,
      ~navbar_item_third: option(navbar_item)=?,
      ~navbar_item_fourth: option(navbar_item)=?,
      ~actions: list(navbar_action)=[],
    ) => {
  let infoList = [navbar_item_first, navbar_item_second, navbar_item_third, navbar_item_fourth];

  let visibleActionsLimit = 4;

  let visibleActions =
    List.length(actions) > visibleActionsLimit
      ? actions->ReasonReactUtils.sliceList(visibleActionsLimit) : actions;

  let menuActions: list(MenuList.menu_item) =
    List.length(actions) > visibleActionsLimit
      ? actions->ReasonReactUtils.sliceList(~start=visibleActionsLimit, List.length(actions))
        |> List.map(action => MenuList.{item_label: action.label, item_cb: action.on_select_cb})
      : [];

  <Row className="navbar">
    <Row className="navbar__titleInfo">
      <Title title />
      <Row className="navbar__ctaList">
        {infoList
         |> List.mapi((key: int, info: option(navbar_item)) =>
              switch (info) {
              | Some(info) =>
                <Row key={string_of_int(key)} className="navbar__ctaListItem">
                  <div className="navbar__infoKey"> {React.string(info.label)} </div>
                  <div className="navbar__infoValue">
                    {switch (info.value) {
                     | Text(value) => React.string(value)
                     | Custom(fn) => fn()
                     | NoText => React.null
                     }}
                  </div>
                </Row>
              | None => React.null
              }
            )
         |> ReasonReactUtils.listToReactArray}
      </Row>
    </Row>
    <Row className="navbar__ctaList">
      {visibleActions |> getActionButtons |> ReasonReactUtils.listToReactArray}
      {List.length(menuActions) == 0
         ? React.null : <MenuList menuButtonTitle="More..." menuItems=menuActions />}
    </Row>
  </Row>;
};
