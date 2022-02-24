[@react.component]
let make = () => {
  let ts_initial = 1645646264000.0;
  let date_str = "2022-02-23";

  let tz_dubai = "Asia/Muscat";

  let tz_india = "Asia/Kolkata";

  let tz_canada = "Canada/Eastern";

  TimestampV3.Date.setDefaultTz(tz_dubai);

  let ts_moment_dubai = TimestampV3.Timestamp.fromFloat(ts_initial, tz_dubai);
  let ts_string_dubai = TimestampV3.Timestamp.toString(ts_initial, tz_dubai);

  Js.log2("ts_moment_dubai", ts_moment_dubai);

  let ts_moment_india = TimestampV3.Timestamp.fromFloat(ts_initial, tz_india);
  let ts_string_india = TimestampV3.Timestamp.toString(ts_initial, tz_india);

  Js.log2("ts_moment_india", ts_moment_india);

  let ts_moment_canada = TimestampV3.Timestamp.fromFloat(ts_initial, tz_canada);
  let ts_string_canada = TimestampV3.Timestamp.toString(ts_initial, tz_canada);

  Js.log2("ts_moment_canada", ts_moment_canada);

  let date_dubai = TimestampV3.Date.fromString(date_str, "DD/MM/YYYY");
  let date_to_str_dubai = TimestampV3.Date.toString(date_dubai);
  let date_dubai_tm = TimestampV3.Date.tomorrow()->TimestampV3.Date.toString;

  Js.log2("date_dubai", date_dubai);
  Js.log2("tm_dubau", date_dubai_tm);

  let date_india = TimestampV3.Date.fromString(date_str, "DD/MM/YYYY");
  let date_to_str_india = TimestampV3.Date.toString(date_india);
  let date_india_tm = TimestampV3.Date.tomorrow()->TimestampV3.Date.toString;

  Js.log2("date_india", date_india);
  Js.log2("tm_india", date_india_tm);

  let date_canada = TimestampV3.Date.fromString(date_str, "DD/MM/YYYY");
  let date_to_str_canada = TimestampV3.Date.toString(date_canada);
  let date_canada_tm =
    TimestampV3.Date.tomorrow()->TimestampV3.Date.toString;

  Js.log2("date_canada", date_canada);
  Js.log2("tm_canada", date_canada_tm);

  <div>
    <div> {React.string("India ->>> date_to_str_india " ++ date_to_str_india)} </div>
    <div> {React.string("Dubai ->>> date_to_str_dubai " ++ date_to_str_dubai)} </div>
    <div> {React.string("Canada ->>> date_to_str_canada " ++ date_to_str_canada)} </div>
    <div> {React.string("India ->>> tomorrow ->>>> " ++ date_india_tm)} </div>
    <div> {React.string("Dubai ->>> tomorrow ->>>> " ++ date_dubai_tm)} </div>
    <div> {React.string("Canada ->>> tomorrow ->>>> " ++ date_canada_tm)} </div>
  </div>;
  /* <FormInput.DateV2
       input_props={FormInput.make_props(
         ~label="",
         ~onChange=_ => (),
         ~result=Some(Ok(None)),
         (),
       )}
       date_props={FormInput.DateV2.make_props(
         ~value=date_dubai->Some,
         ~minDate=min_date->Some,
         ~maxDate=Some(max_date),
         ~onChange=date => {update_ts(_ => date->TimestampV2.fromDate)},
         ~format="DD/MM/YYYY",
         (),
       )}
     /> */
  /* <div> {React.string("India ->>> ts_string_india " ++ ts_string_india)} </div>
     <div> {React.string("Dubai ->>> ts_string_dubai " ++ ts_string_dubai)} </div>
     <div> {React.string("Canada ->>> ts_string_canada " ++ ts_string_canada)} </div> */
  /* <div>

     </div> */
};
