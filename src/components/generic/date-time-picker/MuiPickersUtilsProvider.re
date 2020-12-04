[@bs.module "@date-io/moment"] external utils: Js.t('a) = "default";

[@bs.module "@material-ui/pickers"] [@react.component]
external make: (~utils: Js.t('a), ~children: React.element) => React.element =
  "MuiPickersUtilsProvider";
