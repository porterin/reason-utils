open ButtonTypes;

let handleSubmit = (event: ReactEvent.Mouse.t, callback: _ => unit) => {
  ReactEvent.Mouse.stopPropagation(event);
  callback(event);
};

[@react.component]
let make = (~buttonProps: buttonProps) => {
  <ButtonLabelDecorator label={buttonProps.label}>
    {(labelElement: React.element) =>
       <MaterialUi.Button
         size=`Small
         disableRipple=true
         disabled={buttonProps.disabled}
         className={
           "button " ++ (!buttonProps.disabled ? "primary-button " : "") ++ buttonProps.className
         }
         onClick={(event: ReactEvent.Mouse.t) => handleSubmit(event, buttonProps.onSelectCB)}>
         {buttonProps.prefixIcon}
         labelElement
         {buttonProps.postfixIcon}
       </MaterialUi.Button>}
  </ButtonLabelDecorator>;
};
