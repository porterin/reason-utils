type t = Js.Date.t;

let setTz = (tz: string) => {
  MomentUtils.setTz(tz);
};

let toJsDate = (d: t): Js.Date.t => d;

let fromJsDate = (d: Js.Date.t): t => d;

let make = (~value: string, ~format: string): t =>
  MomentUtils.fromString(~date=value, ~format)->MomentUtils.toJsDate;

let toString = (~format: string, ~date: t) => MomentUtils.formatFromJsDate(~format, ~date);

let now = (): t => MomentUtils.now()->MomentUtils.toJsDate;

let isBefore = (~first_date: t, ~second_date: t) => {
  MomentUtils.isBefore(
    ~first_date=MomentUtils.fromJsDate(first_date),
    ~second_date=MomentUtils.fromJsDate(second_date),
  );
};

let isAfter = (~first_date: t, ~second_date: t) => {
  MomentUtils.isAfter(
    ~first_date=MomentUtils.fromJsDate(first_date),
    ~second_date=MomentUtils.fromJsDate(second_date),
  );
};

let getDateTimeAfterElapsedTime = (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time,
    ~time_unit,
    ~initial_date=MomentUtils.fromJsDate(initial_date),
  )
  ->MomentUtils.toJsDate;
};

let tomorrow = (): t => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time=float_of_int(1),
    ~time_unit=Days,
    ~initial_date=MomentUtils.now(),
  )
  ->MomentUtils.toJsDate;
};

let getDateTimeBeforeElapsedTime =
    (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => {
  MomentUtils.getDateTimeBeforeElapsedTime(
    ~elapsed_time,
    ~time_unit,
    ~initial_date=MomentUtils.fromJsDate(initial_date),
  )
  ->MomentUtils.toJsDate;
};

let getPreviousDateByDays = (~day: int) => {
  getDateTimeBeforeElapsedTime(
    ~elapsed_time=float_of_int(day),
    ~time_unit=Days,
    ~initial_date=now(),
  );
};

//Decode
let t_decode = json => {
  Decco.stringFromJson(json)->Belt.Result.map(date => date |> Js.Date.fromString |> fromJsDate);
};

//Encode
let t_encode = date => {
  date->toJsDate->Js.Date.toJSONUnsafe->Decco.stringToJson;
};

let toFloat = (date: t): float => {
  MomentUtils.fromJsDate(date)->MomentUtils.toFloat;
};
