%bs.raw
{|require(`../src/components/styles/main.scss`)|};

[@react.component]
let make = () => {
  <>
    <MaterialUi_Lab.Autocomplete
      options=[|Any("text"), Any("text1")|]
      renderInput={sone => {
        Js.log(sone);
        React.string("text");
      }}
    />
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
  </>;
};
