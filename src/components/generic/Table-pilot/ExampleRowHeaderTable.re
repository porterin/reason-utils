type testdata = {
  data: string,
  data1: string,
  data2: string,
  data3: string,
};

[@react.component]
let make = (): React.element => {
  <div className="table-wrapper">
    <TableRowHeaderComponent
      columns={TableSchema.[
        { 
          column: Text("Column"),
          accessor: (t) => Text(t.data)
        },
        { 
          column: Text("Column1"),
          accessor: (t) => Text(t.data1)
        },
        { 
          column: Text("Column2"),
          accessor: (t) => Text(t.data2)
        },
        { 
          column: Text("Column3"),
          accessor: (t) => Text(t.data3)
        },
      ]}
      className="customTable"
      rowData= [
        GroupTableSchema.{
          label: Text("14th October"),
          rows: [
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"}
          ]
        },
        GroupTableSchema.{
          label: Text("13th October"),
          rows: [
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"}
          ]
        },
        GroupTableSchema.{
          label: Text("12th October"),
          rows: [
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"},
            {data: "sample", data1: "sample", data2: "sample", data3: "sample"}
          ]
        }
      ]
    />
  </div>;
};
