type momentAdapter;

module LocalizationProvider = {
  [@bs.module "@material-ui/pickers4"] [@react.component]
  external make: (~dateAdapter: momentAdapter, ~children: React.element) => React.element =
    "LocalizationProvider";
};

module DatePicker = {
  [@bs.module "@material-ui/pickers4"] [@react.component]
  external make:
    (
      ~renderInput: 'a => React.element,
      ~value: option(MomentTz.Moment.t),
      ~onChange: MomentTz.Moment.t => unit,
      ~ampm: bool
    ) =>
    React.element =
    "DatePicker";
};

module TimePicker = {
  [@bs.module "@material-ui/pickers4"] [@react.component]
  external make:
    (
      ~renderInput: 'a => React.element,
      ~value: option(MomentTz.Moment.t),
      ~onChange: Js.Nullable.t(MomentTz.Moment.t) => unit,
      ~ampm: bool=?,
      ~inputFormat: string
    ) =>
    React.element =
    "TimePicker";
};

[@bs.module "./MomentAdapter"]
external getMomentAdapter: unit => momentAdapter = "getMomentAdapter";

module TextField = {
  module TextFieldBinding = {
    [@bs.module "@material-ui/core"] [@react.component]
    external make: (~label: option(string)=?, ~placeholder: option(string)=?) => React.element =
      "TextField";
  };

  let make = (~props, ~label, ~placeholder) =>
    ReasonReact.cloneElement(<TextFieldBinding label placeholder />, ~props, [||]);
};
