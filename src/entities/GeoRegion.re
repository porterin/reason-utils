type t =
  | Mumbai
  | Delhi
  | Bangalore
  | Hyderabad
  | Chennai
  | Ahmedabad
  | Pune
  | Surat
  | Kolkata;

let cities: list(t) = [Mumbai, Bangalore, Delhi, Hyderabad, Chennai, Ahmedabad, Pune, Surat, Kolkata];

let toString = (region: t): string =>
  switch (region) {
  | Mumbai => "Mumbai"
  | Delhi => "Delhi NCR"
  | Bangalore => "Bangalore"
  | Hyderabad => "Hyderabad"
  | Chennai => "Chennai"
  | Ahmedabad => "Ahmedabad"
  | Pune => "Pune"
  | Surat => "Surat"
  | Kolkata => "Kolkata"
  };

let fromString = (region: string): t =>
  switch (region) {
  | "Mumbai" => Mumbai
  | "Delhi NCR"
  | "Delhi" => Delhi
  | "Bangalore" => Bangalore
  | "Hyderabad" => Hyderabad
  | "Chennai" => Chennai
  | "Ahmedabad" => Ahmedabad
  | "Pune" => Pune
  | "Surat" => Surat
  | "Kolkata" => Kolkata
  | _ => failwith("No geo-region found for given string")
  };

let getList = (): list(string) => {
  cities |> List.map((region: t) => toString(region));
};