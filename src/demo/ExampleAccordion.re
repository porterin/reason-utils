let data: list(AccordionTypes.t) = [
  {
    header: Text("Order History"),
    footer: <div> {React.string("Test Data")} </div>,
    body: <div> {React.string("Test Data")} </div>,
  },
  {
    header: Text("Suspension Info"),
    footer: <div> {React.string("Test Data")} </div>,
    body: <div> {React.string("Test Data")} </div>,
  },
  {
    header: Text("Tickets"),
    footer: <div> {React.string("Test Data")} </div>,
    body: <div> {React.string("Test Data")} </div>,
  },
  {
    header: Text("Partner Earnings"),
    footer: <div> {React.string("Test Data")} </div>,
    body: <div> {React.string("Test Data")} </div>,
  },
];

[@react.component]
let make = (): React.element => {
  <Accordion panels=data className="accordion-container" />;
};
