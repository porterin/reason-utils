let buildDeletableChip = (~title: string, ~onDelete: unit => unit) => {
  <MaterialUi.Chip
    label={React.string(title)}
    onDelete={_evt => onDelete()}
    size=`Small
  />
};

[@react.component]
let make = (~title: string, ~onDelete: unit => unit) => buildDeletableChip(~title, ~onDelete);
