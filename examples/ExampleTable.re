%bs.raw
{|require(`../src/components/styles/main.scss`)|};

module Customer = {
  type t = {
    id: int,
    name: string,
  };
};

let getTableSchema = () => {
  TableSchema.[
    {column: Text("Source"), accessor: (apr: Customer.t) => Text(apr.id |> string_of_int)},
    {column: Text("Customer"), accessor: (apr: Customer.t) => Text(apr.name)},
  ];
};

[@react.component]
let make = () => {
  let customers: list((Customer.t, TableCell.t)) = [
    (Customer.{id: 1, name: "Porter"}, Custom(_ => React.string("Porter"))),
  ];

  let accordionPanels: list(AccordionTypes.t) = [
    {
      header: Text("test"),
      footer: <div />,
      body: <div />,
      onOpen: _ => Js.log("Accordion working")
    },
    {
      header: Text("test2"),
      footer: <div />,
      body: <div />,
      onOpen: _ => Js.log("Accordion working 2")
    }
  ]

  let (snackbarCmp, openSnackbar) = ToastSnackbarHook.useSnackbar(~duration=1000, ());

  <div>
    <div className="header"> {React.string("Header Bar")} </div>
    snackbarCmp
    <TableWithAccordions
      columns={getTableSchema()}
      class_name="customTable"
      rows=customers
      is_sticky_header=true
      collapsible_row_class_name="accordion-row"
    />
    <button onClick={_ => openSnackbar(Success("fdfdf"))}> {React.string("Success")} </button>
    <button onClick={_ => openSnackbar(Error("fdfdf"))}> {React.string("Error")} </button>

    <Accordion panels=accordionPanels />
  </div>;
};
