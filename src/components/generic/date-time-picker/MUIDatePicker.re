[@bs.module "@material-ui/pickers"] [@react.component]
external make:
  (
    ~onChange: MomentTz.Moment.t => unit,
    ~value: MomentTz.Moment.t,
    ~autoOk: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableFuture: option(bool),
    ~disablePast: option(bool),
    ~disableToolbar: option(bool)=?,
    ~format: option(string)=?,
    ~maxDate: option(MomentTz.Moment.t),
    ~maxDateMessage: React.element=?,
    ~minDate: option(MomentTz.Moment.t),
    ~minDateMessage: React.element=?,
    ~shouldDisableDate: option(MomentTz.Moment.t => bool)=?,
    ~variant: option(string)=?,
    ~label: option(string)=?,
    ~inputVariant: option(string)=?,
    ~className: option(string)=?
  ) =>
  React.element =
  "DatePicker";
