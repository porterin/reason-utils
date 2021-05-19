module Anchor = {
  type t =
    | Right
    | Left
    | Top
    | Bottom;
  let make = (a: t): MaterialUi_Drawer.anchor => {
    switch (a) {
    | Right => `Right
    | Left => `Left
    | Top => `Top
    | Bottom => `Bottom
    };
  };
};

module Classes = {
  type t = {
    root: string,
    docked: string,
    paper: string,
    paperAnchorLeft: string,
    paperAnchorRight: string,
    paperAnchorTop: string,
    paperAnchorBottom: string,
    paperAnchorDockedLeft: string,
    paperAnchorDockedTop: string,
    paperAnchorDockedRight: string,
    paperAnchorDockedBottom: string,
    modal: string,
  };
  let make =
      (
        ~root: string="",
        ~docked: string="",
        ~paper: string="",
        ~paperAnchorLeft: string="",
        ~paperAnchorRight: string="",
        ~paperAnchorTop: string="",
        ~paperAnchorBottom: string="",
        ~paperAnchorDockedLeft: string="",
        ~paperAnchorDockedTop: string="",
        ~paperAnchorDockedRight: string="",
        ~paperAnchorDockedBottom: string="",
        ~modal: string="",
        _unit,
      )
      : t => {
    root,
    docked,
    paper,
    paperAnchorLeft,
    paperAnchorRight,
    paperAnchorTop,
    paperAnchorBottom,
    paperAnchorDockedLeft,
    paperAnchorDockedTop,
    paperAnchorDockedRight,
    paperAnchorDockedBottom,
    modal,
  };
};

[@react.component]
let make =
    (
      ~_open: bool,
      ~anchor: Anchor.t=Right,
      ~toggleSidebar: unit => unit,
      ~children: React.element,
      ~className="",
      ~classes: option(Classes.t)=?,
    ) => {
  <MaterialUi.Drawer
    classes={
      switch (classes) {
      | Some(classes) =>
        MaterialUi.Drawer.Classes.make(
          ~root=classes.root,
          ~docked=classes.docked,
          ~paper=classes.paper,
          ~paperAnchorLeft=classes.paperAnchorLeft,
          ~paperAnchorRight=classes.paperAnchorRight,
          ~paperAnchorTop=classes.paperAnchorTop,
          ~paperAnchorBottom=classes.paperAnchorBottom,
          ~paperAnchorDockedLeft=classes.paperAnchorDockedLeft,
          ~paperAnchorDockedTop=classes.paperAnchorDockedTop,
          ~paperAnchorDockedRight=classes.paperAnchorDockedRight,
          ~paperAnchorDockedBottom=classes.paperAnchorDockedBottom,
          ~modal=classes.modal,
          (),
        )
      | None => MaterialUi.Drawer.Classes.make()
      }
    }
    className
    _open
    anchor={Anchor.make(anchor)}
    onClose={_ => toggleSidebar()}>
    children
  </MaterialUi.Drawer>;
};
