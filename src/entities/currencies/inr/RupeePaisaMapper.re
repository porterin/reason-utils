let rupeeToPaisa = (a: Rupee.t): Paisa.t =>
  a |> Rupee.fromRupee |> (r => r *. 100.0 |> int_of_float |> Paisa.toPaisa);

let paisaToRupee = (a: Paisa.t): Rupee.t =>
  a |> Paisa.fromPaisa |> float_of_int |> (p => p /. 100.0 |> Rupee.toRupee);
