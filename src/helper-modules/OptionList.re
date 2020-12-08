module type SelectListConfig = {type uniqueIdType;};

module OptionListModule = (OptionListConfig: SelectListConfig) => {
  type optionRecord = {
    id: OptionListConfig.uniqueIdType,
    description: string,
  };
};
