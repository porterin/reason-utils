%bs.raw
{|require(`../src/components/styles/main.scss`)|};

[@react.component]
let make = () => {
  <>
    <PrimaryButton
      buttonProps={ButtonUtils.getDefaultButtonProps(
        ~label=Text("Okay"),
        ~onSelectCB=_ => (),
        (),
      )}
    />
    <SecondaryButton
      buttonProps={ButtonUtils.getDefaultButtonProps(
        ~label=Text("Okay"),
        ~onSelectCB=_ => (),
        (),
      )}
    />
    // <Autocomplete label="autocomplete "id="autocomplete" options=[|{label: "1"},{label: "2"},{label: "3"}|] />
  </>;
};
