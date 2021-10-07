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

  <div>
    <div className="header"> {React.string("Header Bar")} </div>
    <TableWithAccordions
      columns={getTableSchema()}
      class_name="customTable"
      rows=customers
      is_sticky_header=true
      collapsible_row_class_name="accordion-row"
    />
  </div>;
};
