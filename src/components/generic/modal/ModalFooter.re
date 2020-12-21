let closeIcon = AssetsManager.getImage("ic-info-outline.svg");

[@react.component]
let make = (~label: string, ~isDisabled: bool=false, ~cb: _ => unit, ~error=None) => {
  switch (error) {
  | Some(error) =>
    <div className="porter-form__section">
      <div className="porter-form__row">
        <img src=closeIcon />
        <div
          className="porter-form__submitError"
          dangerouslySetInnerHTML={"__html": ErrorUtils.resolveError(~error)}
        />
      </div>
      <button className="btn-primary--green"> {React.string("Submit")} </button>
    </div>
  | None =>
    <div className="porter-form__section">
      <button disabled=isDisabled className="btn-primary--green" onClick={_ => cb()}>
        {React.string(label)}
      </button>
    </div>
  };
};
