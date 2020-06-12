open ResponseHandlerCommon;

module NoContentConfig = {
  type responseDataType = NoContent.t;
  let execute = data => CommonStateMapper.NoContentHandler.execute(~_json=data);
};

module NoContentResponseConverter = ResponseConverter(NoContentConfig, DefaultErrorConverter);

module PostApiConfig = {
  type responseDataType = ApiResponse.t;
  let execute = data => CommonStateMapper.PostApiHandler.execute(~json=data);
};

module PostApiResponseConverter = ResponseConverter(PostApiConfig, DefaultErrorConverter);
