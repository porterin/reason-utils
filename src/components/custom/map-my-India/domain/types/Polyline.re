type options = {
  color: string,
  weight: int,
  opacity: float,
};

type polylineOptions = {
  color: option(string),
  weight: option(int),
  opacity: option(float),
};

type coordinate = (float, float);

type routeCoordinates = list(coordinate);
