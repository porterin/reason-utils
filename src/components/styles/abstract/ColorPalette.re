type t = 
 | DarkGreen
 | StatusRed

let getClassName  :(t) => string =
  fun
  | DarkGreen => "u-status-green"
  | StatusRed => "u-status-red"