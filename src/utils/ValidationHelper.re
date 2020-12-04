module MobileNumber = {
  let isValid = (mobileNUmber: string) => {
    let regex = [%bs.re "/^[6-9]{1}[0-9]{9}$/"];
    switch (Js.Re.exec_(regex, mobileNUmber)) {
    | Some(_str) => true
    | _ => false
    };
  };
};

module Msisdn = {
  let getMsisdnRegex = () =>
    switch (Env.node_env) {
    | "staging" =>
      %bs.re
      "/^[1-9]{1}[0-9]{12}$/"
    | _ =>
      %bs.re
      "/^[6-9]{1}[0-9]{12}$/"
    };

  let isValid = (msisdn: CommonTypes.msisdn): bool => {
    switch (Js.Re.exec_(getMsisdnRegex(), msisdn)) {
    | Some(_str) => true
    | _ => false
    };
  };
};

