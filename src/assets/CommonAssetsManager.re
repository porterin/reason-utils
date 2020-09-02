let getImage = name => {
  let requireImage = [%raw
    {|
      function(name){
        return require(name).default
      }
    |}
  ];
  requireImage(name);
};

// let importFavicon = () => {
//   %bs.raw
//   {|require('CommonAssets/favicon.ico').default|};
// };
