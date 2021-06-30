[@react.component]
let make = (~progress_bar_class: string, ~is_completed: bool, ~is_in_active: bool) => {
  <div
    className={
      "progress-bar "
      ++ progress_bar_class
      ++ (is_completed && is_in_active ? " progress-bar-completed" : "")
    }
  />;
};
