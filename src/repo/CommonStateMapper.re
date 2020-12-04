module NoContentHandler = {
  let execute = (~_json: Js.Json.t): NoContent.t => {
    {title: "Resource Created", message: "Resource successfully created"};
  };
};

module PostApiHandler = {
  let execute = (~json: Js.Json.t): ApiResponse.t =>
    Json.Decode.{
      status: json |> field("status", int),
      message: json |> field("message", string),
    };
};
