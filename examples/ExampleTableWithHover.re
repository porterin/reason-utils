%bs.raw
{|require(`../src/components/styles/main.scss`)|};

module Customer = {
  type t = {
    id: int,
    name: string,
  };
};

let getTableSchema = () => {
  TableSchemaV2.[
    make_props(
      ~column=Text("Source"),
      ~accessor=(apr: Customer.t) => Text(apr.id |> string_of_int),
      ~is_visible_only_on_hover=true,
      (),
    ),
    make_props(~column=Text("Customer"), ~accessor=(apr: Customer.t) => Text(apr.name), ()),
  ];
};

[@react.component]
let make = () => {
  let customers: list(Customer.t) = [Customer.{id: 1, name: "Porter"}, {id: 2, name: "Aman"}];

  let (snackbarCmp, openSnackbar) = ToastSnackbarHook.useSnackbar(~duration=1000, ());

  <div>
    <div className="header"> {React.string("Header Bar")} </div>
    snackbarCmp
    <TableComponentV2 columns={getTableSchema()} className="customTable" rowData=customers />
    <button onClick={_ => openSnackbar(Success("fdfdf"))}> {React.string("Success")} </button>
    <button onClick={_ => openSnackbar(Error("fdfdf"))}> {React.string("Error")} </button>
  </div>;
};
