let onTabClick = (isActiveTab: bool, onTabSelectCB: _ => unit) => {
  if(!isActiveTab) {
    onTabSelectCB()
  } else {
    ()
  }
};

let getCloseBtn = (~tabIndex: int, ~label: string, ~onTabCloseCB: string => unit) => {
  (
    tabIndex !== 0 ?
      <span 
        className="tab-item__close-btn"
        onClick={
          (event: ReactEvent.Mouse.t) => {
            onTabCloseCB(label)
            ReactEvent.Mouse.stopPropagation(event)	
          }
        }
      >
      (React.string("x"))
      </span>
    : 
    React.null
  )
};

[@react.component]
let make = (
	~label : string,
	~isActive : bool, 
	~onTabSelectCB: string => unit ,
	~onTabCloseCB: string => unit,
	~tabIndex: int,
) => {
	  <div
			className={isActive ? "tab-item-active tab-item": "tab-item-inactive tab-item"}
			onClick={(_event) => {onTabClick(isActive, (_ => onTabSelectCB(label)))}}>
			{React.string(label)}
      {getCloseBtn(~tabIndex, ~label, ~onTabCloseCB)}
		</div>
};
