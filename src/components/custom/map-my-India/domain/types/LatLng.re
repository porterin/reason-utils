type t = {
  lat: float,
  lng: float,
};

type bounds = {
  .
  _south_west: t,
  _north_east: t,
};

type boundOptions = {
  paddingTopLeft: array(int),
  paddingBottomRight: array(int),
};
