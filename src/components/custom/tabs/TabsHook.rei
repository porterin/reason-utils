type t('a) = {
  tabId: 'a,
  label: CommonTypes.viewText,
  icon: React.element,
  disabled: bool,
  tooltip: option(string),
};

let useTabs: (~tabs: list(t('a)), ~defaultActive: 'a) => (React.element, 'a);
