let toString = (distance: float) => {
  distance->Js.Float.toString
  ++ {
    distance > 1.0 ? " KMS" : " KM";
  };
};
