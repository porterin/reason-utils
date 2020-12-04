[@react.component]
let make = (~text: string, ~cb: _ => unit, ~className="", ~disabled=false) => {
    <button
      className=(className == "" ? "btn" : className)
      disabled=disabled  
      onClick=(cb)>
        (React.string(text))
    </button>
}
