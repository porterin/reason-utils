module IntDecoderConfig = {
  type fieldType = int;
  let fieldDecoder = Json.Decode.int;
};

module IntDecoder = MaybeFieldDecoder.Decoder(IntDecoderConfig);

module StringDecoderConfig = {
  type fieldType = string;
  let fieldDecoder = Json.Decode.string;
};

module StringDecoder = MaybeFieldDecoder.Decoder(StringDecoderConfig);
