%bs.raw
{|require(`../src/components/styles/main.scss`)|};

let data: list(AccordionTypes.t) = [
  AccordionTypes.make_props(
    ~header=Text("Order History"),
    ~body=<div> {React.string("Test Data")} </div>,
    (),
  ),
  AccordionTypes.make_props(
    ~header=Text("Suspension Info"),
    ~footer=<div> {React.string("Test Data")} </div>,
    ~body=<div> {React.string("Test Data")} </div>,
    (),
  ),
  AccordionTypes.make_props(
    ~header=Text("Tickets"),
    ~footer=<div> {React.string("Test Data")} </div>,
    ~body=<div> {React.string("Test Data")} </div>,
    (),
  ),
  AccordionTypes.make_props(
    ~header=Text("Partner Earnings"),
    ~footer=<div> {React.string("Test Data")} </div>,
    ~body=<div> {React.string("Test Data")} </div>,
    (),
  ),
];

[@react.component]
let make = (): React.element => {
  <AccordionV2 panels=data className="accordion-container" />;
};
