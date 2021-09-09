module Customer = {
  type t = {
    id: int,
    name: string,
  };
};

let getTableSchema = () => {
  TableSchema.[
    {
      column: Text("Source"),
      accessor: (apr: Customer.t) => Text(apr.id |> string_of_int),
    },
    {
      column: Text("Customer"),
      accessor: (apr: Customer.t) => Text(apr.name),
    },
  ];
};

[@react.component]
let make = () => {
  let customers: list((Customer.t, TableCell.t)) = [
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
    (Customer.{id: 1, name: "Aman"}, Custom(_ => React.string("aman"))),
  ];

  <div>
    <div className="header"> {React.string("Header Bar")} </div>
    <TableCollapsingRowComponent
      columns={getTableSchema()}
      className="customTable"
      rowData=customers
    />
  </div>;
};
