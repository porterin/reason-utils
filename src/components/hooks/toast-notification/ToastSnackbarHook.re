let success_tick = AssetsManager.getImage("success-tick.svg");
let error_cross = AssetsManager.getImage("error-cross.svg");

type snackbar_message =
  | Success(string)
  | Error(string);

let useSnackbar = (~duration: int=3000, ()) => {
  let (snackbar, toggle_snackbar) = React.useState(_ => false);
  let (message, setMessage) = React.useState(_ => Success(""));
  let snackbarComp =
    <Snackbar
      position=(Snackbar.PositionV.Bottom, Snackbar.PositionH.Left)
      autoHideDuration=duration
      is_open=snackbar
      onClose={(_, _) => toggle_snackbar(_ => false)}>
      <div>
        {switch (message) {
         | Success(msg) =>
           <div className="c-toast-notification-snackbar success">
             <img src=success_tick />
             {React.string(msg)}
           </div>
         | Error(msg) =>
           <div className="c-toast-notification-snackbar error">
             <img src=error_cross />
             {React.string(msg)}
           </div>
         }}
      </div>
    </Snackbar>;
  (
    snackbarComp,
    message => {
      setMessage(_ => message);
      toggle_snackbar(_ => true);
    },
  );
};
