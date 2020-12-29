module type TargetEventWrapper = {
  let value: ReactEvent.Form.t => string;
  let checked: ReactEvent.Form.t => bool;
  let file: ReactEvent.Form.t => FileInput.t
};

module type TargetListEventWrapper = {let listValue: ReactEvent.Form.t => list('a);};

module type TargeMouseEventWrapper = {let value: ReactEvent.Mouse.t => string;};

module TargetEventWrapper = {
  type target = {
    value: string,
    checked: bool,
    files: array(FileInput.t)
  };

  external target: Js.t({..}) => target = "%identity";
  let target = (event): target => event->ReactEvent.Form.target->target;

  let value = event => event->target.value;

  let checked = event => event->target.checked;

  let file = event => event->target.files[0];
};

module TargetListEventWrapper = {
  type listTarget('a) = {value: array('a)};
  external listTarget: Js.t({..}) => listTarget('a) = "%identity";

  let listTarget = (event): listTarget('a) => event->ReactEvent.Form.target->listTarget;

  let listValue = event => event->listTarget.value->Array.to_list;
};

module TargetMouseEventWrapper = {
  type target = {
    value: string
  };

  external target: Js.t({..}) => target = "%identity";

  let target = (event): target => event->ReactEvent.Mouse.target->target;

  let value = event => event->target.value;
};
