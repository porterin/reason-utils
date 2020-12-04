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
    classes=[Root("mui-tab-root"), Selected("mui-tab-selected")]
  />;
};

let createTabs = (tabs: list(t('a)), setActiveTab: ('a => 'a) => unit) => {
  tabs
  |> List.mapi((index, tab) => {
       switch (tab.tooltip) {
       | None => getTab(tab, index, setActiveTab)
       | Some(content) =>
         <TooltipComponent content>
           <div> {getTab(tab, index, setActiveTab)} </div>
         </TooltipComponent>
       }
     })
  |> ReasonReactUtils.listToReactArray;
};

let useTabs = (~tabs: list(t('a)), ~defaultActive: 'a) => {
  let (activeTab, setActiveTab) = React.useState(_ => defaultActive);
  let tabComponent =
    <MaterialUi.Tabs
      value=activeTab classes=[Root("mui-tabs-root"), Indicator("mui-tabs-indicator")]>
      {createTabs(tabs, setActiveTab)}
    </MaterialUi.Tabs>;

  (tabComponent, activeTab);
};
