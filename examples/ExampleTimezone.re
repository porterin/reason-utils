let unixToMs = (u: int) => {
  u->float_of_int *. 1000.0;
};

[@react.component]
let make = () => {
  let ts = 1645497513000.0->Timestamp.make;
  let _date = Date.make(~value="2021-04-07", ~format="YYYY-MM-DD");
  let ts_now = Timestamp.now();

  <div>
    <div>
      {React.string(
         "India ->>> "
         ++ Timestamp.toStringWithTz(~ts, ~offset=5.5, ~format="DD/MM/YYYY hh:mm A"),
       )}
    </div>
    <div>
      {React.string(
         "Dubai ->>> "
         ++ Timestamp.toStringWithTz(~ts, ~offset=4.0, ~format="DD/MM/YYYY hh:mm A"),
       )}
    </div>
    <div>
      {React.string(
         "Dubai ->>> "
         ++ Timestamp.toStringWithTz(~ts=ts_now, ~offset=5.5, ~format="DD/MM/YYYY hh:mm A"),
       )}
    </div>
  </div>;
};
