[@react.component]
let make = (~height: string, ~onScrollEndCallback: (unit => unit), ~children) => {
  let onScrollCallback = (event) => {
    let scrollHeight = ReactEvent.Synthetic.target(event)##scrollHeight;
    let clientHeight = ReactEvent.Synthetic.target(event)##clientHeight;
    let scrollTop = ReactEvent.Synthetic.target(event)##scrollTop;

    if(scrollTop + clientHeight >= scrollHeight){
      onScrollEndCallback();
    }
  };

  <div style=(ReactDOMRe.Style.make(~height, ~overflowY="scroll", ())) onScroll={onScrollCallback}>
    {children}
  </div>
};
