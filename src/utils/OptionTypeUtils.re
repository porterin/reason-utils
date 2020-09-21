let getStringFrmOptionalType = (data): string => {
  switch (data) {
  | Some(data) => data
  | None => "N/A"
  };
};

let getEmptyStringFrmOptionalType = (data): string => {
  switch (data) {
  | Some(data) => data
  | None => ""
  };
};

let getIntFrmOptionalType = (data): int => {
  switch (data) {
  | None => 0
  | Some(data) => data
  };
};

let getIntFrmOptionalTypeStrict = (data): int => {
  switch (data) {
  | None => raise(Not_found)
  | Some(data) => data
  };
};

let getFloatFrmOptionalTypeStrict = (data): float => {
  switch (data) {
  | None => raise(Not_found)
  | Some(data) => data
  };
};

let getDateFrmOptionalType = (data: option(Js.Date.t)): Js.Date.t => {
  switch (data) {
  | None => Js.Date.fromString("N/A")
  | Some(data) => data
  };
};

let getDateStringFromOptionType = (date: option(Js.Date.t)): string => {
  switch (date) {
  | None => "N/A"
  | Some(date) => DateTime.toString(~format="Do MMM YY HH:mm", date)
  };
};

let getDateFromOptionalString = (date: option(string), format: string): option(Js.Date.t) => {
  switch (date) {
  | None => None
  | Some(date) => Some(DateTime.fromString(~format, date))
  };
};

let optionResolver = case =>
  switch (case) {
  | Some(value) => value
  | None => failwith("not found")
  };

let getListFromOptionalType = (li: option(list('a))): list('a) => {
  switch (li) {
  | None => []
  | Some(li) => li
  };
};
