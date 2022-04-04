type marks = {
  value: int,
  label: string,
};

type valueLabelProps = {
  children: React.element,
  open_: bool,
  value: int,
};

let marksToAny = (marks: list(marks)): list(MaterialUi_Types.any) => {
  marks |> List.map(mark => MaterialUi_Types.Any(mark));
};

[@react.component]
let make =
    (
      ~className: string="",
      ~aria_labelledby: string="",
      ~valueLabelComponent: option(valueLabelProps => React.element)=?,
      ~min: int,
      ~max: int,
      ~marks: list(marks),
      ~onChange: (ReactEvent.Form.t, int) => unit,
      ~value: int,
      ~valueLabelFormat: string=""
    ) => {
  <MaterialUi.Slider
    className
    aria_labelledby
    valueLabelDisplay=`On
    _ValueLabelComponent={MaterialUi.Slider.ValueLabelComponent.valueLabelComponent_func(
      MaterialUi_Types.Any(valueLabelComponent),
    )}
    min={MaterialUi_Types.Number.int(min)}
    max={MaterialUi_Types.Number.int(max)}
    marks={MaterialUi.Slider.Marks.array(marks |> marksToAny |> Array.of_list)}
    onChange
    value={MaterialUi.Slider.Value.int(value)}
    valueLabelFormat={MaterialUi.Slider.ValueLabelFormat.string(valueLabelFormat)}
    classes={MaterialUi.Slider.Classes.make(
      ~root="slider-root",
      ~thumb="slider-thumb",
      ~valueLabel="slider-valueLabel",
      ~track="slider-track",
      ~rail="slider-rail",
      ~mark="slider-mark",
      ~markActive="slider-markActive",
      (),
    )}
  />;
};
