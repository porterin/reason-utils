[@react.component]
let make = (~text="Loading") => {
  <div className="u-margin-bottom-small u-margin-top-small u-text-centre loader-container">
    <h3 className="header__h3">(React.string(text))</h3>
    <div className="loader u-margin-0-auto"></div>
  </div>
}
