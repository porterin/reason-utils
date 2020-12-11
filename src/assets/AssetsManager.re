let getImage = name => {
  let requireImage = [%raw
    {|
      function(name){
        return require(`Assets/images/${name}`).default
      }
    |}
  ];
  requireImage(name);
};

let importFavicon = () => {
  %bs.raw
  {|require('Assets/favicon.ico').default|};
};
