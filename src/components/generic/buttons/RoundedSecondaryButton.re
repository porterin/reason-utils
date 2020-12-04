open ButtonTypes;

let handleSubmit = (event: ReactEvent.Mouse.t, callback: ReactEvent.Mouse.t => unit) => {
  ReactEvent.Mouse.stopPropagation(event);
  callback(event);
};

[@react.component]
let make = (~buttonProps: buttonProps) => {
  <ButtonLabelDecorator label={buttonProps.label}>
    {(labelElement: React.element) =>
       <MaterialUi.Fab
         variant=`Extended
         size={buttonProps.size}
         disableRipple=true
         disabled={buttonProps.disabled}
         className={
           "round-button "
           ++ (!buttonProps.disabled ? "secondary-button " : "")
           ++ buttonProps.className
         }
         onClick={(event: ReactEvent.Mouse.t) => handleSubmit(event, buttonProps.onSelectCB)}>
         {buttonProps.prefixIcon}
         labelElement
         {buttonProps.postfixIcon}
       </MaterialUi.Fab>}
  </ButtonLabelDecorator>;
};
