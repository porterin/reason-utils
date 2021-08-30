type scrollViewOptions = {
  behavior: string,
  block: string,
  inline: string,
};

[@bs.send]
external scrollIntoView: (Dom.element, scrollViewOptions) => _ =
  "scrollIntoView";
[@bs.val] [@bs.scope "document"] external getElement: string => Dom.element = "getElementById";


let scrollToTop = (ele: Dom.element) => {
  let scrollViewProps: scrollViewOptions = {
    behavior: "smooth",
    block: "end",
    inline: "nearest",
  };
  scrollIntoView(ele, scrollViewProps);
};

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
    <div id="scroll-top" />
    {children}
    <button style=(ReactDOMRe.Style.make(~bottom="0", ~position="fixed", ())) onClick={_ => scrollToTop(getElement("scroll-top"))}>{React.string("To Top")} </button>
  </div>
};
