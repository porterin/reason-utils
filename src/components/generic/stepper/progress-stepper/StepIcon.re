let complete_tick = AssetsManager.getImage("white-tick.svg");

[@react.component]
let make = (~index: int, ~is_completed: bool) => {
  <div>
    {is_completed
       ? <span className="step-icon"> <img src=complete_tick /> </span>
       : <span className="step-index"> {React.int(index + 1)} </span>}
  </div>;
};
