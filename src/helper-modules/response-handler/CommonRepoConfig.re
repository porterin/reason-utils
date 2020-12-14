open ResponseHandler;

module NoContentConfig = {
  type responseDataType = NoContent.t;
  let execute = data => GenericResponseMapper.NoContentHandler.execute(~_json=data);
};

module NoContentResponseConverter = ResponseConverter(NoContentConfig, DefaultErrorConverter);

module PostApiConfig = {
  type responseDataType = ApiResponse.t;
  let execute = data => GenericResponseMapper.PostApiHandler.execute(~json=data);
};

module PostApiResponseConverter = ResponseConverter(PostApiConfig, DefaultErrorConverter);
