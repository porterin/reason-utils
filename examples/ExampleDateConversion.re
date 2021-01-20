let str = React.string;

[@react.component]
let make = () => {
  let date = DateTime.now();
  <div>
    {str(DateTime.toString(date))}
  </div>

};
