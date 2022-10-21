[@bs.module "mui-pickers/dist"] [@react.component]
external make:
  (~date: option(MomentTz.Moment.t), ~handleDateChange: MomentTz.Moment.t => unit, ~tz: string) =>
  React.element =
  "TimePickerBinding";
