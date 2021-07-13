type rupee = float;
type paisa = int;
type fixedRupee = int;

let toRupee = (a: float): rupee => a;

let toPaisa = (a: int): paisa => a;

let toFixedRupee = (a: int): fixedRupee => a;

let paiseToRupee = (a: paisa): rupee => float_of_int(a) /. 100.0;

let rupeeToPaisa = (a: rupee): paisa => {
  Js.Float.toFixedWithPrecision(a, ~digits=2)->Js.Float.fromString
  |> (v => (v *. 100.0)->int_of_float);
};

let fixedRupeeToPaisa = (a: fixedRupee): paisa => a * 100;

let paisaToFixedRupee = (a: paisa): fixedRupee => a / 100;
