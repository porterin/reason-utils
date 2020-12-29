open Belt.Option;
open FormValidationUtils;

type input('a) =
  | Opt(input('a)): input(option('a))
  | String(string): input(string)
  | Int(string): input(int)
  | Float(string): input(float)
  | Date(string, string): input(MomentRe.Moment.t);

let rec getValue: type a. input(a) => result(a, string) =
  input => {
    let str_opt = str => str == "" ? None : Some(str);
    switch (input) {
    | String(str) =>
      str->str_opt->mapWithDefault(Error("This is a required field"), str => Ok(str))
    | Int(str) =>
      str
      ->str_opt
      ->mapWithDefault(Error("This is a required field"), str =>
          if (isIntegerStringValid(str)) {
            int_of_string(str) > 0
              ? Ok(int_of_string(str)) : Error("Value greater than 0 required");
          } else {
            Error("Please enter a valid number");
          }
        )
    | Date(str, format) =>
      str
      ->str_opt
      ->mapWithDefault(Error("This is a required field"), str =>
          Ok(MomentRe.momentWithFormat(str, format))
        )
    | Float(str) =>
      str
      ->str_opt
      ->mapWithDefault(Error("This is a required field"), str =>
          if (isFloatStringValid(str)) {
            Ok(float_of_string(str));
          } else {
            Error("Please enter a valid decimal number");
          }
        )
    | Opt(wrapped_type) =>
      switch (getValue(wrapped_type)) {
      | Ok(value) => Ok(Some(value))
      | Error(err) =>
        switch (err) {
        | "This is a required field" => Ok(None)
        | _ => Error(err)
        }
      }
    };
  };
