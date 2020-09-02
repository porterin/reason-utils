[@react.component]
let make = (~text) => {
  <label className="porter-form__label"> {React.string(text)} </label>;
};
