[@bs.module "@material-ui/pickers"] [@react.component]
external make:
  (
    ~onChange: Js.Nullable.t(MomentRe.Moment.t) => unit,
    ~value: MomentRe.Moment.t,
    ~ampm: option(bool)=?,
    ~autoOk: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableToolbar: option(bool)=?,
    ~format: option(string)=?,
    ~disableToolbar: option(bool)=?,
    ~maxDateMessage: React.element=?,
    ~minDateMessage: React.element=?,
    ~invalidDateMessage: option(React.element)=?,
    ~variant: option(string)=?,
    ~inputVariant: option(string)=?,
    ~minutesStep: option(int)=?,
    ~label: option(string)=?,
    ~className: option(string)=?,
    ~mask: option(string)=?,
    ~views: option(array(string))=?,
    ~placeholder: option(string)=?
  ) =>
  React.element =
  "KeyboardTimePicker";
