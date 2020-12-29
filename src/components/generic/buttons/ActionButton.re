[@react.component]

let make = (~btnText: string, ~clickCallback: _ => unit,~isDisabled: bool) => 
    <a 
      className="btn-tertiary--blue"
      style=(isDisabled ? ReactDOMRe.Style.make(~pointerEvents="none", ~color="grey", ()) : ReactDOMRe.Style.make(()))
      onClick={(_event) => clickCallback()}>
        <span className="actionBtn__text">(React.string(btnText))</span>
    </a>

