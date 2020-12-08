module type DecoderConfig = {
  type fieldType;
  let fieldDecoder: Js.Json.t => fieldType;
};

module Decoder = (Config: DecoderConfig) => {
  let decode = (json: Js.Json.t): Config.fieldType => {
    Json.Decode.(json |> field("value", Config.fieldDecoder));
  };
};
