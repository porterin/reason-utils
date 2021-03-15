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
    root: string,
    anchorOriginTopLeftroot: string,
    anchorOriginTopCenter: string,
    anchorOriginBottomCenter: string,
    anchorOriginTopRight: string,
    anchorOriginBottomRight: string,
    anchorOriginTopLeft: string,
    anchorOriginBottomLeft: string
  };

let make_props =
  (
    ~root: string="",
    ~anchorOriginTopLeftroot: string="",
    ~anchorOriginTopCenter: string="",
    ~anchorOriginBottomCenter: string="",
    ~anchorOriginTopRight: string="",
    ~anchorOriginBottomRight: string="",
    ~anchorOriginTopLeft: string="",
    ~anchorOriginBottomLeft: string="",
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
  ~autoHideDuration=1500, 
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
                ~root=classes.root,
                ~anchorOriginTopCenter=classes.anchorOriginTopCenter,
                ~anchorOriginBottomCenter=classes.anchorOriginBottomCenter,
                ~anchorOriginTopRight=classes.anchorOriginTopRight,
                ~anchorOriginBottomRight=classes.anchorOriginBottomRight,
                ~anchorOriginTopLeft=classes.anchorOriginTopLeft,
                ~anchorOriginBottomLeft=classes.anchorOriginBottomLeft,
                ()
              )
          }
          | None => MaterialUi_Snackbar.Classes.make(())
        }
      )
    >
      (children)
    </MaterialUi.Snackbar>
}
