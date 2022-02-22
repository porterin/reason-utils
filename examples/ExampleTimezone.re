let unixToMs = (u: int) => {
  u->float_of_int *. 1000.0;
};

[@react.component]
let make = () => {
  let ts_initial = TimestampV2.utc();
  let _date = Date.make(~value="2021-04-07", ~format="YYYY-MM-DD");

  let tomorrow = TimestampV2.tomorrow();

  let (ts, update_ts) = React.useState(_ => ts_initial);

  let value = TimestampV2.toDate(~ts, ~offset=-5.0);
  let min_date = TimestampV2.toDate(~ts, ~offset=-5.0);
  let max_date =
    TimestampV2.toDate(
      ~ts=
        TimestampV2.getDateTimeAfterElapsedTime(
          ~elapsedTime=180.0,
          ~timeUnit=`days,
          ~initialDate=TimestampV2.toDate(~ts, ~offset=-5.0),
        ),
      ~offset=-5.0,
    );

  Js.log3(value, min_date, max_date);

  <div>
    <div>
      {React.string(
         "India ->>> " ++ TimestampV2.toString(~ts, ~offset=5.5, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Canada ->>> "
         ++ TimestampV2.toString(~ts, ~offset=-5.0, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Dubai ->>> " ++ TimestampV2.toString(~ts, ~offset=4.0, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Tomorrow ->>> "
         ++ TimestampV2.toString(~ts=tomorrow, ~offset=-5.0, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Today ->>> " ++ TimestampV2.toString(~ts, ~offset=-5.0, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Min date ->>> "
         ++ TimestampV2.toString(~ts, ~offset=-5.0, ~format="DD/MM/YYYY hh:mm A ZZ"),
       )}
    </div>
    <div>
      {React.string(
         "Max_date ->>> "
         ++ TimestampV2.toString(
              ~ts=
                TimestampV2.getDateTimeAfterElapsedTime(
                  ~elapsedTime=180.0,
                  ~timeUnit=`days,
                  ~initialDate=TimestampV2.toDate(~ts, ~offset=5.5),
                ),
              ~offset=5.5,
              ~format="DD/MM/YYYY hh:mm A ZZ",
            ),
       )}
    </div>
    <div>
      <FormInput.DateV2
        input_props={FormInput.make_props(
          ~label="",
          ~onChange=_ => (),
          ~result=Some(Ok(None)),
          (),
        )}
        date_props={FormInput.DateV2.make_props(
          ~value=value->Some,
          ~minDate=min_date->Some,
          ~maxDate=Some(max_date),
          ~onChange=date => {update_ts(_ => date->TimestampV2.fromDate)},
          ~format="DD/MM/YYYY",
          (),
        )}
      />
    </div>
  </div>;
};
