[@react.component]
let make =
    (
      ~title: string,
      ~warning: option(string),
      ~tableData: list(RowDataType.t),
      ~cb=_ => (),
      ~isDisabled=false
    ) => {
  isDisabled
    ? <div className="card-component__display">
        <Row className="card-component__title">
          <div className="text-styling-text u-text-bold u-opacity-light">
            {React.string(title)}
          </div>
          {
            switch warning {
            | None => React.null
            | Some(warning) =>  <div className="card-component__warning"> {React.string(warning)} </div>
            };
          }
        </Row>
        <div className="u-opacity-light">
          <CardTableComponentV2 tableData />
        </div>
      </div>
    : <div
        className="card-component__display card-component__display-on-hover"
        onClick={_event => cb()}>
        <div className="text-styling-text u-text-bold">
          {React.string(title)}
        </div>
        <CardTableComponentV2 tableData />
      </div>;
};
