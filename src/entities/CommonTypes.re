type auth_token = string;
type language = string;
type text = string;
type minutes = int;
type money = int;
[@decco.decode]
type amount = float;
[@decco.decode]
type days = int;

/* partner */
type msisdn = string;

/* order */
type order_id = string;

type location = {
  lat: string,
  lng: string,
};

type name = string;

type mobile = string;

type date = Js.Date.t;

type viewText =
  | Text(string)
  | NoText
  | Custom(unit => React.element);
