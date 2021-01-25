include FormInputProps;

module Date = {
  include FormDateInput;
};

module DateTime = {
  include FormDateTimeInput;
};

module Time = {
  include FormTimeInput;
};

module KeyInputTime = {
  include FormKeyInputTime;
};

module RadioGroup = {
  include FormRadioGroupInput;
};

module Select = {
  include FormSelectInput;
};

module CheckBox = {
  include FormCheckBoxInput;
};

module SelectCheckBoxes = {
  include FormSelectWithCheckboxInput;
};

module TextInput = {
  include FormTextInput;
};

type formInput =
  | Input(string)
  | Date(Date.t)
  | DateTime(DateTime.t)
  | Time(Time.t)
  | KeyInputTime(KeyInputTime.t)
  | RadioGroup(RadioGroup.t)
  | Select(Select.t)
  | CheckBox(CheckBox.t)
  | SelectCheckBoxes(SelectCheckBoxes.t);

[@react.component]
let make = (~input_props: FormInputProps.t('b, 'c), ~value: formInput) => {
  switch (value) {
  | Date(date_params) => <Date input_props date_props=date_params />
  | DateTime(date_params) => <DateTime input_props date_props=date_params />
  | Time(time_params) => <Time input_props time_props=time_params />
  | KeyInputTime(time_params) => <KeyInputTime input_props time_props=time_params />
  | RadioGroup(params) => <RadioGroup input_props radio_props=params />
  | Select(params) => <Select input_props select_props=params />
  | CheckBox(params) => <CheckBox input_props checkbox_props=params />
  | SelectCheckBoxes(params) => <SelectCheckBoxes input_props select_props=params />
  | Input(value) => <TextInput input_props value />
  };
};
