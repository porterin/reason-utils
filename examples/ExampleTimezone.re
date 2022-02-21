let unixToMs = (u: int) => {
  u->float_of_int *. 1000.0;
};

[@react.component]
let make = () => {
  let ts = 1645406195000.0->Timestamp.make;
  let date = Date.make(~value="2021-04-07", ~format="YYYY-MM-DD");

  <div>
    <div>
      {React.string(
         "India ->>> " ++ Date.toStringWithTz(~date, ~offset=5.5, ~format="DD/MM/YYYY"),
       )}
    </div>
    <div>
      {React.string(
         "Dubai ->>> " ++ Timestamp.toStringWithTz(~ts, ~offset=4.0, ~format="DD/MM/YYYY"),
       )}
    </div>
  </div>;
};
