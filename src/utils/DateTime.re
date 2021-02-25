type t = Js.Date.t;

open MomentRe;

type moment = Moment.t;

let largeYear = 3100;
let defaultFormat = "DD-MM-YYYY HH:mm";

let now = (): t => {
  Js.Date.fromFloat(Js.Date.now());
};

let toMoment = (date: t): Moment.t => {
  momentWithDate(date);
};

let fromMoment = (moment: Moment.t): t => {
  Moment.toDate(moment);
};

let toString = (~format: string=defaultFormat, date: t) => {
  Moment.format(format, momentWithDate(date));
};

let momentWithFormat = (date: string, format: string) => {
  date -> momentWithFormat(format)
}

let fromString = (~format: string=defaultFormat, dateString: string): t => {
  Moment.toDate(momentWithFormat(dateString, format));
};

let toSecond = (date: t): int => {
  toString(~format="HH:mm:ss", date)->durationFormat->Duration.asSeconds->int_of_float;
};

let toMinute = (date: t): int => {
  toString(~format="HH:mm", date)->durationFormat->Duration.asMinutes->int_of_float;
};

let fromTimeStamp = (timestamp: int) => {
  Moment.toDate(momentWithUnix(timestamp));
};

let toTimeStamp = (date: t) => {
  Moment.toUnix(momentWithDate(date));
};

let fromMilliTimestamp = (timestamp: float) => {
  let toUnixTimestamp = (timestamp) => timestamp/.1000.;
  timestamp
    -> toUnixTimestamp
    -> int_of_float 
    -> fromTimeStamp 
}

let isSame = (firstDate: t, secondDate: t) => {
  Moment.isSame(momentWithDate(firstDate), momentWithDate(secondDate));
};

let isAfter = (firstDate: t, secondDate: t) => {
  Moment.isAfter(momentWithDate(firstDate), momentWithDate(secondDate));
};

let isBefore = (firstDate: t, secondDate: t) => {
  Moment.isBefore(momentWithDate(firstDate), momentWithDate(secondDate));
};

let getDateTimeAfterElapsedTime =
    (
      elapsedTime: float,
      timeUnit: [
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
      initialDate: t,
    ) => {
  let toDuration = duration(elapsedTime, timeUnit);
  let toMoment = Moment.add(~duration=toDuration, momentWithDate(initialDate));
  Moment.toDate(toMoment);
};

let tomorrow = () => {
  getDateTimeAfterElapsedTime(float_of_int(1), `days, Js.Date.fromFloat(Js.Date.now()));
};

let getYesterday = () => {
  getDateTimeAfterElapsedTime(float_of_int(-1), `days, Js.Date.fromFloat(Js.Date.now()));
};

let calculateEndDate = (endTime: t, format: string) => {
  endTime
  |> Js.Date.getFullYear
  |> int_of_float
  |> (
    effectiveTillYear => effectiveTillYear >= largeYear ? "Lifetime" : toString(endTime, ~format)
  );
};

let diffDates =
    (
      ~startDate: Js.Date.t,
      ~endDate: Js.Date.t,
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
    )
    : float =>
  diff(momentWithDate(endDate), momentWithDate(startDate), timeUnit);

let startOf = (date: Js.Date.t, scale) => {
  date |> toMoment |> Moment.startOf(scale) |> fromMoment
};

let endOf = (date: Js.Date.t, scale) => {
  date |> toMoment |> Moment.endOf(scale) |> fromMoment
};

let toUtc = (date: string) => {
  date -> momentUtc |> fromMoment
};

let isValid = (date: Js.Date.t) => {
  date |> toMoment |> Moment.isValid
};

let format = (date: Js.Date.t, format: string) => {
  date |> toMoment |> Moment.format(format)
}

let day = (date: Js.Date.t) => {
  date -> toMoment -> Moment.day
}
