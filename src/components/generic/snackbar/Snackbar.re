module PositionV = {
  type t =
  | Top
  | Bottom;

  let toSnackbarVertical :(t) => MaterialUi_Snackbar.Vertical.t =
    fun
    | Top => MaterialUi_Snackbar.Vertical.top
    | Bottom => MaterialUi_Snackbar.Vertical.bottom
}

module PositionH = {
  type t =
  | Right
  | Left
  | Centre

  let toSnackbarHorizontal :(t) => MaterialUi_Snackbar.Horizontal.t =
    fun
    | Right => MaterialUi_Snackbar.Horizontal.right
    | Left => MaterialUi_Snackbar.Horizontal.left
    | Centre => MaterialUi_Snackbar.Horizontal.center
};

module Classes = {
  type t = {
    root: option(string),
    anchorOriginTopLeftroot: option(string),
    anchorOriginTopCenter: option(string),
    anchorOriginBottomCenter: option(string),
    anchorOriginTopRight: option(string),
    anchorOriginBottomRight: option(string),
    anchorOriginTopLeft: option(string),
    anchorOriginBottomLeft: option(string)
  };

let make_props =
  (
    ~root: option(string)=?,
    ~anchorOriginTopLeftroot: option(string)=?,
    ~anchorOriginTopCenter: option(string)=?,
    ~anchorOriginBottomCenter: option(string)=?,
    ~anchorOriginTopRight: option(string)=?,
    ~anchorOriginBottomRight: option(string)=?,
    ~anchorOriginTopLeft: option(string)=?,
    ~anchorOriginBottomLeft: option(string)=?,
    (),
  )
  : t => {
    root,
    anchorOriginTopLeftroot,
    anchorOriginTopCenter,
    anchorOriginBottomCenter,
    anchorOriginTopRight,
    anchorOriginBottomRight,
    anchorOriginTopLeft,
    anchorOriginBottomLeft,
  }
};

[@react.component]
let make = (
  ~is_open: bool, 
  ~autoHideDuration=150, 
  ~position=(PositionV.Bottom, PositionH.Centre),
  ~onClose: (ReactEvent.Synthetic.t, string) => unit,
  ~className: option(string)=?,
  ~classes: option(Classes.t)=?,
  ~children: React.element
) =>  {
  let (vertical, horizontal) = position;
    <MaterialUi.Snackbar
      _open=is_open
      autoHideDuration=MaterialUi_Types.Number.int(autoHideDuration)
      anchorOrigin=MaterialUi_Snackbar.AnchorOrigin.make(
        ~horizontal=PositionH.toSnackbarHorizontal(horizontal),
        ~vertical=PositionV.toSnackbarVertical(vertical),
        ()
      )
      onClose
      className=Belt.Option.getWithDefault(className, "")
      classes=(
        switch(classes) {
          | Some(classes) => {
              MaterialUi_Snackbar.Classes.make(
                ~root=Belt.Option.getWithDefault(classes.root, ""),
                ~anchorOriginTopCenter=Belt.Option.getWithDefault(classes.anchorOriginTopCenter, ""),
                ~anchorOriginBottomCenter=Belt.Option.getWithDefault(classes.anchorOriginBottomCenter, ""),
                ~anchorOriginTopRight=Belt.Option.getWithDefault(classes.anchorOriginTopRight, ""),
                ~anchorOriginBottomRight=Belt.Option.getWithDefault(classes.anchorOriginBottomRight, ""),
                ~anchorOriginTopLeft=Belt.Option.getWithDefault(classes.anchorOriginTopLeft, ""),
                ~anchorOriginBottomLeft=Belt.Option.getWithDefault(classes.anchorOriginBottomLeft, ""),
                ()
              )
          }
          | None => MaterialUi_Snackbar.Classes.make(
              ()
            )
        }
      )
    >
      (children)
    </MaterialUi.Snackbar>
}
