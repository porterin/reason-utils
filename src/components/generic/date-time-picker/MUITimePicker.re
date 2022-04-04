[@bs.module "@material-ui/pickers"] [@react.component]
external make:
  (
    ~onChange: MomentTz.Moment.t => unit,
    ~value: MomentTz.Moment.t,
    ~ampm: option(bool)=?,
    ~autoOk: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableToolbar: option(bool)=?,
    ~format: option(string)=?,
    ~disableToolbar: option(bool)=?,
    ~maxDateMessage: React.element=?,
    ~minDateMessage: React.element=?,
    ~invalidDateMessage: option(string)=?,
    ~variant: option(string)=?,
    ~inputVariant: option(string)=?,
    ~minutesStep: option(int)=?,
    ~label: option(string)=?,
    ~className: option(string)=?
  ) =>
  React.element =
  "TimePicker";
