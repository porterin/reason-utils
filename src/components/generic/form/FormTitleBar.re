let closeIcon = AssetsManager.getImage("close.svg");

[@react.component]
let make = (~title: string, ~onCloseCb: _ => _) => {
  <div className="titlebar">
    <div className="titlebar__title"> {React.string(title)} </div>
    <div className="titlebar__close" onClick={_event => onCloseCb()}> <img src=closeIcon /> </div>
  </div>;
};
