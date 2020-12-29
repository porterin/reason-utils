[@react.component]
let make = (~link: string, ~className="", ~children: React.element) => {
    <a
      href=link
      className=("link" ++ " " ++ className)
      target="_blank"
      >
        {children}
    </a>
};
