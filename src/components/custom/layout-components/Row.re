[@react.component]
let make = (~children: React.element, ~className: string = "") => {
   <div className=("u-flex__row " ++ className)>
      children
   </div>       
}
