let useTabs = (~tabs: list(MuiTabs.t('a)), ~defaultActive: 'a) => {
  let (activeTab, setActiveTab) = React.useState(_ => defaultActive);
  let tabComponent = <MuiTabs tabs activeTab setActiveTab />;
  (tabComponent, activeTab);
};
