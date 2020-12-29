type t =
  | Active
  | Inactive
  | NotAvailable;

let fromString = (value: string): t => {
  switch (value) {
  | "active" => Active
  | "inactive" => Inactive
  | "notAvailable" => NotAvailable
  | _ => ErrorUtils.raiseError(~path="CrmAccordionStatus.re", ~message="Invalid status", ~value)
  };
};

let toString = (value: t) => {
  switch (value) {
  | Active => "Active"
  | Inactive => "Inactive"
  | NotAvailable => "Not Available"
  };
};
