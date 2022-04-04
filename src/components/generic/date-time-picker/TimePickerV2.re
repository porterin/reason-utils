open MomentTz;
[@bs.module "rc-time-picker"] [@react.component]
external make:
  (
    ~value: Moment.t,
    ~defaultValue: Moment.t,
    ~onChange: option(Moment.t => unit)=?,
    ~format: option(string)=?,
    ~className: option(string)=?,
    ~placement: option(string)=?,
    ~minuteStep: option(int)=?,
    ~showSecond: bool,
    ~_open: option(bool)=?,
    ~clearIcon: React.element,
    ~onOpen: option(_ => unit)=?,
    ~onClose: option(_ => unit)=?
  ) =>
  React.element =
  "default";
