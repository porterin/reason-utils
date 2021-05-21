type t('a) = {
  tabId: 'a,
  label: CommonTypes.viewText,
  icon: React.element,
  disabled: bool,
  tooltip: option(string),
};

let getTab = (tab: t('a), index: int, setActiveTab: ('a => 'a) => unit) => {
  <MaterialUi.Tab
    key={string_of_int(index)}
    onClick={_ => setActiveTab(_ => tab.tabId)}
    label={
      <Row className="mui-tab-label">
        <div className="icon"> {tab.icon} </div>
        {switch (tab.label) {
         | Text(label) => <div> {React.string(label)} </div>
         | Custom(fn) => fn()
         | NoText => React.null
         }}
      </Row>
    }
    disabled={tab.disabled}
    classes={MaterialUi.Tab.Classes.make(~root="mui-tab-root", ~selected="mui-tab-selected", ())}
  />;
};

[@react.component]
let make = (~tabs: list(t('a)), ~activeTab: 'a, ~setActiveTab: ('a => 'a) => unit) => {
  <MaterialUi.Tabs
    value={MaterialUi_Types.Any(activeTab)}
    classes={MaterialUi.Tabs.Classes.make(
      ~root="mui-tabs-root",
      ~indicator="mui-tabs-indicator",
      (),
    )}>
    {tabs
     |> List.mapi((index, tab) => {
          switch (tab.tooltip) {
          | None => getTab(tab, index, setActiveTab)
          | Some(content) =>
            <TooltipComponent content>
              <div> {getTab(tab, index, setActiveTab)} </div>
            </TooltipComponent>
          }
        })
     |> ReasonReactUtils.listToReactArray}
  </MaterialUi.Tabs>;
};
