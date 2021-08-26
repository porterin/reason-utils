// type scrollViewOptions = {
//   behavior: string,
//   top: int,
//   left: int,
// };

// let scrollToTop = (refrence: React.ref('a)) => {
//   let scrollOptions = {
//     behavior: "smooth",
//     top: 0,
//     left: 0
//   }
//   switch (refrence.current->Js.Nullable.toOption) {
//   | None => ()
//   | Some(r) => ReactDOMRe.domElementToObj(r)##scroll(scrollOptions)
//   };
// };

let scrollToTop = (refrence: React.ref('a)) => {
  switch (refrence.current->Js.Nullable.toOption) {
  | None => ()
  | Some(r) => ReactDOMRe.domElementToObj(r)##scrollTo(0, 0)
  };
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

  let scrollRef = React.useRef(Js.Nullable.null);

  <div style=(ReactDOMRe.Style.make(~height, ~overflowY="scroll", ())) onScroll={onScrollCallback} ref={ReactDOMRe.Ref.domRef(scrollRef)} >
    {children}
    <button style=(ReactDOMRe.Style.make(~bottom="0", ~position="fixed", ())) onClick={_ => scrollToTop(scrollRef)}>{React.string("To Top")} </button>
  </div>
};
