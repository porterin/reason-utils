[@react.component]
let make = (~label: ButtonLabel.t, ~children: React.element => React.element) => {
  switch (label) {
  | Text(label) => children(<div> {React.string(label)} </div>)
  | Custom(fn) => children(fn())
  | Href(label, link) =>
    <a
      className="button-label-decorator"
      onClick={event => ReactEvent.Synthetic.preventDefault(event)}
      href=link>
      {children(<div> {React.string(label)} </div>)}
    </a>
  };
};
