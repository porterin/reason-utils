type options = {
  class_name: string,
  sticky: bool,
  offset: array(int),
};

[@bs.obj]
external createToolTipOpts:
  (
    ~class_name: option(string)=?,
    ~sticky: option(bool)=?,
    ~offset: option(array(int))=?,
    unit
  ) =>
  options;

type toolTipOptions = {
  class_name: option(string),
  sticky: option(bool),
  offset: option(array(int)),
};
