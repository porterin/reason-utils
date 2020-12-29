open ButtonTypes;

[@react.component]
let make = (~actions: list(buttonProps)) => {
  <>
    {switch (List.length(actions)) {
     | 0 => React.null
     | _ =>
       <div className="actions-container">
         {actions
          |> List.map((action: buttonProps) =>
               switch (action.buttonType) {
               | Primary => <RoundedPrimaryButton buttonProps=action />
               | Secondary => <RoundedSecondaryButton buttonProps=action />
               }
             )
          |> ReasonReactUtils.listToReactArray}
       </div>
     }}
  </>;
};
