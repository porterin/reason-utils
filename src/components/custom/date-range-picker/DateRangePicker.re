type dateRange = {
    startDate: option(Date.t),
    endDate: option(Date.t),
};

type definedRange = {
  startDate: option(Date.t),
  endDate: option(Date.t),
  label: string
};

[@bs.module "materialui-daterange-picker/src/components/DateRangePickerExporter.tsx"] [@react.component]
external make:
  (
    ~open_: bool,
    ~toggle: unit => unit,
    ~onChange: dateRange => unit,
    ~initialDateRange: dateRange=?,
    ~definedRanges: array(definedRange)=?,
    ~minDate: Date.t=?,
    ~maxDate: Date.t=?,
    ~closeOnClickOutside: bool=?,
    ~wrapperClassName: string=?
  ) =>
  React.element =
  "default";
