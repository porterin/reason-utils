open AccordionTypes;

let getAccordionHeader = (expanded: bool, panel: t) => {
  <MaterialUi.ExpansionPanelSummary
    className={"header " ++ (expanded ? "expanded-header" : "")}
    expandIcon={
      <Icon.ExpandMoreIcon className="expand-icon" fontSize=`Large />
    }>
    {switch (panel.header) {
     | Text(title) => <div> {React.string(title)} </div>
     | Custom(fn) => fn()
     }}
  </MaterialUi.ExpansionPanelSummary>;
};

let getAccordionBody = (body: React.element) => {
  <MaterialUi.ExpansionPanelDetails> body </MaterialUi.ExpansionPanelDetails>;
};

[@react.component]
let make =
    (~panels: list(t), ~className: string="", ~defaultOpen: int=(-1))
    : React.element => {
  /*
     Expanded represents the index of accordion that is expanded.
     Intial state is set to 0 as to open the first accordion object
     and -1 is used in case no accordion object is opened.
   */
  let (expanded, setExpanded) = React.useState(_ => defaultOpen);
  let handleChange = index => {
    setExpanded(_ => expanded == index ? (-1) : index);
  };

  <div className>
    {panels
     |> List.mapi((index, panel) =>
          <MaterialUi.ExpansionPanel
            key={string_of_int(index)}
            className="accordion"
            expanded={index == expanded}
            onChange={(_, _) => handleChange(index)}>
            {getAccordionHeader(index == expanded, panel)}
            {getAccordionBody(panel.body)}
            {panel.footer}
          </MaterialUi.ExpansionPanel>
        )
     |> ReasonReactUtils.listToReactArray}
  </div>;
};
