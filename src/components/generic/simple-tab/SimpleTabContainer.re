open Tabs;

[@react.component]
let make = (~tabs: list(tab)) => {
  let (currentIndex, setCurrentIndex) = React.useState(() => 0);

  <div className="tabs__container">
    <MaterialUi.Tabs
      value={MaterialUi_Types.Any(currentIndex)}
      className="simple-tab u-position-sticky"
      indicatorColor=`Primary>
      {tabs
       |> List.mapi((index, tab: tab) =>
            <MaterialUi.Tab
              key={string_of_int(index)}
              classes={MaterialUi.Tab.Classes.make(~root="MuiTab-fullWidth tabs_min_width", ())}
              label={React.string(tab.label)}
              onClick={_e => setCurrentIndex(_ => index)}
            />
          )
       |> ReasonReactUtils.listToReactArray}
    </MaterialUi.Tabs>
    <div className="tab-content">
      {tabs
       |> List.mapi((index, tab: tab) => {
            <div key={tab.label} hidden={currentIndex !== index} className="filter-tab">
              {tab.component}
            </div>
          })
       |> ReasonReactUtils.listToReactArray}
    </div>
  </div>;
};
