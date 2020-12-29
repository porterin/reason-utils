module BeltArray = Belt.Array;

type requestBodyField = {
  name: string,
  value: string,
};

let getPostRequestPayload = (inputList: list(requestBodyField)) => {
  let inputArray = Array.of_list(inputList);
  BeltArray.reduce(
    inputArray,
    Js.Dict.empty(),
    (accumulator, inputItem) => {
      Js.Dict.set(accumulator, inputItem.name, Js.Json.string(inputItem.value));
      accumulator;
    },
  )
  |> Js.Json.object_
  |> Js.Json.stringify;
};
