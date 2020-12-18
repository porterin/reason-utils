open Tabs;

[@react.component]
let make =
    (~tabs: tabs, ~currentTab: string, ~onTabSelectCb: string => _, ~onTabCloseCb: string => _) => {
  <div className="tabs__container">
    <div className="tabs__list">
      {tabs.children
       |> List.mapi((index: int, tab: tab) =>
            <TabItemComponent
              key={tab.label}
              label={tab.label}
              isActive={currentTab == tab.label}
              onTabSelectCB={selectedTabLabel => onTabSelectCb(selectedTabLabel)}
              onTabCloseCB={selectedTabLabel => onTabCloseCb(selectedTabLabel)}
              tabIndex=index
            />
          )
       |> ReasonReactUtils.listToReactArray}
    </div>
    <div>
      {tabs.children
       |> List.map((tab: tab) => {
            currentTab === tab.label
              ? <div
                  key={tab.label}
                  className="display-tab"
                  style={ReactDOMRe.Style.make(~display="block", ())}>
                  {tab.component}
                </div>
              : <div
                  key={tab.label}
                  className="no-display-tab"
                  style={ReactDOMRe.Style.make(~display="none", ())}>
                  {tab.component}
                </div>
          })
       |> ReasonReactUtils.listToReactArray}
    </div>
  </div>;
};
