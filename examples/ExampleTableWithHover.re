%bs.raw
{|require(`../src/components/styles/main.scss`)|};

module Customer = {
  type t = {
    id: int,
    name: string,
  };
};

module MenuListBuilder = {
  type t = {
    item: React.element,
    action_cb: unit => unit,
  };

  let execute = (items: list(t)) => {
    items
    |> List.map(({item, action_cb}) => {
         Catalyst.MenuList.{item_label: Custom(() => item), item_cb: () => action_cb()}
       });
  };
};

let getTableSchema = () => {
  TableSchemaV2.[
    make_props(
      ~column=Text("Source"),
      ~accessor=
        (apr: Customer.t) =>
          Custom(
            _ =>
              <Catalyst.MenuList
                custom_menu_button={React.string({j|…|j})}
                menuItems={
                  [
                    {
                      item: React.string("Reactivate"),
                      action_cb: () => {
                        Js.log(apr.id);
                      },
                    },
                  ]
                  ->MenuListBuilder.execute
                }
              />,
          ),
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
