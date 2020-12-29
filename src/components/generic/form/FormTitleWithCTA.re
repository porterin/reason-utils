[@react.component]
let make = (~title: string, ~ctaTitle: string, ~cb: _ => _) => {
  <div className="title_with_cta">
    <div className="u-flex">
      <div className="u-flex-50"> {React.string(title)} </div>
      <div className="u-flex-50 u-flex">
        <a className="title_with_cta__btn btn-tertiary--blue" onClick={_event => cb()}>
          {React.string(ctaTitle)}
        </a>
      </div>
    </div>
    <hr className="porter-form__hr" />
  </div>;
};
