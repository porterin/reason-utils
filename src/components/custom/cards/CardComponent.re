let toggleLogo = AssetsManager.getImage("card-btn-arrow.svg");

[@react.component]
let make =
    (
      ~title: option(string)=?,
      ~className: string="",
      ~footerActionBtn: option(ActionButtonType.t)=?,
      ~children,
    ) => {
  <div className={"card-v3 " ++ className}>
    {switch (title) {
     | None => React.null
     | Some(title) =>
       <div className="header"> <div className="title"> {React.string(title)} </div> </div>
     }}
    <div className="body"> children </div>
    <CardFooterComponent actionBtn=footerActionBtn />
  </div>;
};
