%bs.raw
{|require(`../src/components/styles/main.scss`)|};

let data: list(AccordionTypes.t) = [
  {
    header: Text("Order History"),
    footer: React.null,
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
  <AccordionV2 panels=data className="accordion-container" />;
};
