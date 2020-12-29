[@react.component]
let make = (~cardData: TableDataType.t) =>
  <div className="card-component__main-container">
    <CardHeaderComponent
      title={cardData.title}
      actionBtn={cardData.actionBtnTop}
    />
    <CardTableComponent tableData={cardData.tableData} />
    <CardFooterComponent actionBtn={cardData.actionBtnBot} />
  </div>;
