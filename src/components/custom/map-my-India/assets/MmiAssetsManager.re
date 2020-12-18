let getImage = name => {
  let requireImage = [%raw
    {|
      function(name){
        return require(`./images/${name}`).default
      }
    |}
  ];
  requireImage(name);
};
