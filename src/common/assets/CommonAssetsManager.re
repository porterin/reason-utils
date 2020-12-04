let getImage = name => {
  let requireImage = [%raw
    {|
      function(name){
        return require(`CommonAssets/images/${name}`).default
      }
    |}
  ];
  requireImage(name);
};

let importFavicon = () => {
  %bs.raw
  {|require('CommonAssets/favicon.ico').default|};
};
