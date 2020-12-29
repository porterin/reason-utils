[@react.component]
let make = (~children: React.element, ~className="") => {
   <div className=("u-flex__col " ++ className)>
      children
    </div>       
}
