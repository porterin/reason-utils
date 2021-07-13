type rupee;
type paisa;
type fixedRupee;

let toRupee: float => rupee;

let toPaisa: int => paisa;

let toFixedRupee: int => fixedRupee;

let fromRupee: rupee => float;

let fromPaisa: paisa => int;

let fromFixedRupee: fixedRupee => int;

let paisaToRupee: paisa => rupee;

let rupeeToPaisa: rupee => paisa;

let fixedRupeeToPaisa: fixedRupee => paisa;

let paisaToFixedRupee: paisa => fixedRupee;

let rupeeToString: rupee => string;

let paisaToString: paisa => string;

let fixedRupeeToString: fixedRupee => string;
