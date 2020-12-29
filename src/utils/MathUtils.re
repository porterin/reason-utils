let roundOffToInteger = (number: float) => {
  number |> Pervasives.ceil |> int_of_float;
};
