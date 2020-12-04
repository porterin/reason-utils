type t =
  | Open
  | Allocated
  | Accepted
  | Live
  | Loading
  | Unloading
  | Ended
  | Completed
  | Cancelled
  | Rescheduled;

let fromString = (status: string): t =>
  switch (status) {
  | "open" => Open
  | "allocated" => Allocated
  | "accepted" => Accepted
  | "live" => Live
  | "loading" => Loading
  | "unloading" => Unloading
  | "ended" => Ended
  | "completed" => Completed
  | "cancelled" => Cancelled
  | "rescheduled" => Rescheduled
  | _ =>
    ErrorUtils.raiseError(
      ~path="OrderStatus.re",
      ~message="Invalid order status",
      ~value=status,
    )
  };

let toString = (status: t): string =>
  switch (status) {
  | Open => "open"
  | Allocated => "allocated"
  | Accepted => "accepted"
  | Live => "live"
  | Loading => "loading"
  | Unloading => "unloading"
  | Ended => "ended"
  | Completed => "completed"
  | Cancelled => "cancelled"
  | Rescheduled => "rescheduled"
  };

let t_decode = json =>
  json->Decco.stringFromJson->Belt.Result.map(fromString);
