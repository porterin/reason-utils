type t = Js.Date.t;

let toJsDate = (d): Js.Date.t => d;

let fromJsDate = (d: Js.Date.t): t => d;

let make = (~value: string, ~format: string): t =>
  MomentUtils.fromString(~date=value, ~format)->MomentUtils.toJsDate;

let toString = (~format: string, ~date: t) => MomentUtils.formatFromJsDate(~format, ~date);

//time instances
let now = (): t => MomentUtils.now()->MomentUtils.toJsDate;

let tomorrow = (): t => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time=float_of_int(1),
    ~time_unit=Days,
    ~initial_date=MomentUtils.now(),
  )
  ->MomentUtils.toJsDate;
};

let getDateTimeAfterElapsedTime = (~elapsed_time: float, ~time_unit: TimeUnit.t, ~initial_date: t) => {
  MomentUtils.getDateTimeAfterElapsedTime(
    ~elapsed_time,
    ~time_unit,
    ~initial_date=MomentUtils.fromJsDate(initial_date),
  )
  ->MomentUtils.toJsDate;
};

//validations
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

//calculations
let diffDates =
  (
    ~start_date: t,
    ~end_date: t,
    ~time_unit: TimeUnit.t
  ) => {
  MomentUtils.diffDates(~start_date, ~end_date, ~time_unit)
}
  
//view
let toHoursAndMinutes = (ms: float) => {
  let hrs = (ms /. 3600000.0)->int_of_float;
  let mins = ((ms -. hrs->float_of_int *. 3600000.0) /. 60000.0)->int_of_float;
  
  {
    hrs > 0
      ? hrs->string_of_int
        ++ {
          hrs == 1 ? " hr " : " hrs ";
        }
      : "";
  }
  ++ 
  {
    mins > 0 ? mins->string_of_int ++ " mins" : "";
  };
}