let scrollToBottom = (chatComponentRef: React.ref('a)) => {
    switch(chatComponentRef.current -> Js.Nullable.toOption) {
      | None => ()
      | Some(r) => {
        ReactDOMRe.domElementToObj(r)##scrollTo(0, ReactDOMRe.domElementToObj(r)##clientHeight + 10)
      }
    } 
  };

  [@react.component]
  let make = (
    ~children: React.element
  ) => {
   let chatComponentRef = React.useRef(Js.Nullable.null);
    
    React.useEffect1(() => {
      scrollToBottom(chatComponentRef);
      None
    }, [| children |] );

    <div className="auto-scroll-container" ref={ReactDOMRe.Ref.domRef(chatComponentRef)}>
      children
    </div>
  }
