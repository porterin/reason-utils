let isIntegerStringValid = (intString: string): bool =>
  try(int_of_string(intString) |> (_value => true)) {
  | Failure(_) => false
  };

let isFloatStringValid = (floatString: string): bool =>
  try(float_of_string(floatString) |> (_value => true)) {
  | Failure(_) => false
  };

let isStringNumeric = (str: string): bool => {
  let result = ref(true);
  str
  |> String.iter((numericChar: char) =>
       switch (int_of_char(numericChar)) {
       | code when code >= 48 && code <= 57 => result := result^ && true
       | _ => result := false
       }
     );
  result^;
};

let validateMsisdn = (msisdn: string): Belt.Result.t(string, string) => {
  Js_re.test_([%re "/^(([6-9](\d{12}))|([0]))$/i"], msisdn)
    ? Belt.Result.Ok(msisdn) : Belt.Result.Error("Enter valid msisdn");
};

let validateMobileNumber = (caller_number: string): Belt.Result.t(string, string) => {
  ValidationHelper.MobileNumber.isValid(caller_number)
    ? Belt.Result.Ok(caller_number) : Belt.Result.Error("Enter valid caller number");
};

let validateCRN = (crn: string): Belt.Result.t(string, string) => {
  Js_re.test_([%re "/^(CRN)(\d{8})$/i"], crn)
    ? Belt.Result.Ok(crn) : Belt.Result.Error("Enter valid CRN");
};

let validateEmail = (email: string): Belt.Result.t(string, string) => {
  Js_re.test_(
    [%re
      "/^[A-Z0-9._%+-/!#$%&'*=?^_`{|}~]+@[A-Z0-9.-]+\\.[A-Z]{2,4}$/i"
    ],
    Js.String.toUpperCase(email),
  )
    ? Belt.Result.Ok(email) : Belt.Result.Error("Enter valid Email");
};
