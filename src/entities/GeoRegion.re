type t =
  | Mumbai
  | Delhi
  | Bangalore
  | Hyderabad
  | Chennai
  | Ahmedabad
  | Pune
  | Surat
  | Kolkata
  | Jaipur
  | Lucknow
  | Coimbatore
  | Indore
  | Nagpur;

let getActiveGeoRegions = (): list(t) => [
  Mumbai,
  Bangalore,
  Delhi,
  Hyderabad,
  Chennai,
  Ahmedabad,
  Pune,
  Surat,
  Kolkata,
  Jaipur,
  Lucknow,
  Coimbatore,
  Indore,
  Nagpur,
];

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
  | Jaipur => "Jaipur"
  | Lucknow => "Lucknow"
  | Coimbatore => "Coimbatore"
  | Indore => "Indore"
  | Nagpur => "Nagpur"
  };

/* Better use lowercase city name */
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
  | "Jaipur" => Jaipur
  | "Lucknow" => Lucknow
  | "Coimbatore" => Coimbatore
  | "Indore" => Indore
  | "Nagpur" => Nagpur
  | _ =>
    ErrorUtils.raiseError(
      ~path="GeoRegion.re",
      ~message="No geo-region found for given string",
      ~value=region,
    )
  };

let t_decode = json => json->Decco.stringFromJson->Belt.Result.map(fromString);
