module Timestamp = {
  type t = float;

  let fromFloat = (ts: t, tz: string) => {
    MomentTz.momentWithTimestampMSAndTz(ts, tz);
  };

  let toString = (ts: t, tz: string) => {
    MomentTz.momentWithTimestampMSAndTz(ts, tz)
    |> MomentTz.Moment.format("DD/MM/YYYY hh:mm A ZZ");
  };

  let tomorrow = (): t => {
    MomentUtils.getDateTimeAfterElapsedTime(
      ~elapsed_time=float_of_int(1),
      ~time_unit=Days,
      ~initial_date=MomentUtils.now(),
    )
    ->MomentRe.Moment.valueOf;
  };
};

module Date = {
  type t = Js.Date.t;

  let setDefaultTz: string => unit = [%bs.raw
    {|
      function (tz) {
        MomentTimezone.tz.setDefault(tz);
    }
  |}
  ];

  let fromString = (v: string, _format: string) => {
    MomentTz.moment(v)->MomentTz.Moment.toDate;
  };

  let toString = (v: t) => {
    MomentTz.momentWithDate(v) |> MomentTz.Moment.format("DD/MM/YYYY hh:mm A ZZ");
  };

  let tomorrow = (): t => {
    let toDuration = MomentTz.duration(float_of_int(1), `days);
    MomentTz.Moment.add(~duration=toDuration, MomentTz.momentNow())->MomentTz.Moment.toDate;
  };

  let isBefore = (~first_date: t, ~second_date: t) => {
    MomentTz.Moment.isBefore(
      MomentTz.momentWithDate(first_date),
      MomentTz.momentWithDate(second_date),
    );
  };

  let isAfter = (~first_date: t, ~second_date: t) => {
    MomentTz.Moment.isAfter(
      MomentTz.momentWithDate(first_date),
      MomentTz.momentWithDate(second_date),
    );
  };

  let getDateTimeAfterElapsedTime =
      (
        ~elapsedTime: float,
        ~timeUnit: [
           | `years
           | `quarters
           | `months
           | `weeks
           | `days
           | `hours
           | `minutes
           | `seconds
           | `milliseconds
         ],
        ~initialDate: t,
      )
      : t => {
    let toDuration = MomentTz.duration(elapsedTime, timeUnit);
    MomentTz.Moment.add(~duration=toDuration, MomentTz.momentWithDate(initialDate))
    ->MomentTz.Moment.toDate;
  };
};
