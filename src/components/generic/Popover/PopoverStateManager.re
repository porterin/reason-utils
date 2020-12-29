type config = {
  anchor_el: option(Dom.element),
  view: React.element,
};

let initialState: config = {anchor_el: None, view: React.null};

let usePopover = () => {
  let (state, setState) = React.useState(_ => initialState);
  (state, setState);
};
