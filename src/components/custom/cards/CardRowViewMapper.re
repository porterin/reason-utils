module CardRow = {
  module Row = {
    [@react.component]
    let make = (~parentClassname: string, ~label: string, ~children: React.element) => {
      <div className=parentClassname>
        <div className="key"> {React.string(label)} </div>
        <div className="value"> children </div>
      </div>;
    };
  };

  [@react.component]
  let make = (~parentClassname: string, ~label: string, ~value: CommonTypes.viewText) => {
    switch (value) {
    | NoText => React.null
    | Text(value) => <Row parentClassname label> {React.string(value)} </Row>
    | Custom(fn) => <Row parentClassname label> {fn()} </Row>
    };
  };
};

module CardRecordView = {
  type t = {
    label: string,
    value: CommonTypes.viewText,
  };
  let make = (~className="", lst: list(t)): React.element => {
    lst
    |> List.map((record: t) => {
         <CardRow parentClassname=className label={record.label} value={record.value} />
       })
    |> ReasonReactUtils.listToReactArray;
  };
};

module CardRecordCustomView = {
  type t =
    | RowDisplayObject(CardRecordView.t)
    | ReactElement(React.element);

  let make = (lst: list(t)) => {
    lst
    |> List.map((record: t) => {
         switch (record) {
         | RowDisplayObject(record) =>
           <CardRow parentClassname="order-record" label={record.label} value={record.value} />
         | ReactElement(react_element) => react_element
         }
       })
    |> ReasonReactUtils.listToReactArray;
  };
};
