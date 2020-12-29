[@bs.module "@material-ui/pickers"] [@react.component]
external make:
  (
    ~onChange: MomentRe.Moment.t => unit,
    ~value: MomentRe.Moment.t,
    ~autoOk: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableFuture: option(bool),
    ~disablePast: option(bool),
    ~disableToolbar: option(bool)=?,
    ~format: option(string)=?,
    ~maxDate: option(MomentRe.Moment.t),
    ~maxDateMessage: React.element=?,
    ~minDate: option(MomentRe.Moment.t),
    ~minDateMessage: React.element=?,
    ~shouldDisableDate: option(MomentRe.Moment.t => bool)=?,
    ~variant: option(string)=?,
    ~label: option(string)=?,
    ~inputVariant: option(string)=?,
    ~className: option(string)=?
  ) =>
  React.element =
  "DateTimePicker";
