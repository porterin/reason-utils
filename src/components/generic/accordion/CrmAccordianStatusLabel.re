let getStatusClassName = (status: CrmAccordionStatus.t): string => {
  switch (status) {
  | Active => "status-active"
  | Inactive => "status-inactive"
  | NotAvailable => "status-not-available"
  };
};

[@react.component]
let make = (~status: CrmAccordionStatus.t) => {
  <div className={getStatusClassName(status)}>
    {React.string(CrmAccordionStatus.toString(status))}
  </div>
}
