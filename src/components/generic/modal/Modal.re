[@bs.module][@react.component]
external make:
  (
    ~isOpen: option(bool)=?,
    ~onAfterOpen: option(unit => unit)=?,
    ~onRequestClose: option(unit => unit)=?,
    ~closeTimeoutMS: option(int)=?,
    ~style: option(Js.t({..}))=?,
    ~contentLabel: option(string)=?,
    ~portalClassName: option(string)=?,
    ~overlayClassName: option(string)=?,
    ~className: option(string)=?,
    ~bodyOpenClassName: option(string)=?,
    ~htmlOpenClassName: option(string)=?,
    ~ariaHideApp: option(bool)=?,
    ~shouldFocusAfterRender: option(bool)=?,
    ~shouldCloseOnOverlayClick: option(bool)=?,
    ~shouldCloseOnEsc: option(bool)=?,
    ~shouldReturnFocusAfterClose: option(bool)=?,
    ~role: option(string)=?,
    ~parentSelector: option(unit => React.element)=?,
    ~aria: option(Js.t({..}))=?,
    ~data: option(Js.t({..}))=?,
    ~overlayRef: option(unit => unit)=?,
    ~contentRef: option(unit => unit)=?,
    ~children: React.element
  ) => React.element = "react-modal";
