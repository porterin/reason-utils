type url;

[@bs.new] external create_URL: (string, string) => url = "URL";

[@bs.new] external create_webworker: url => WebWorker.t = "Worker";

[@bs.val] [@bs.scope ("import", "meta")] external importMetaUrl: string = "url";

let execute = (~modulePath: string) => {
  create_webworker(create_URL(modulePath, importMetaUrl));
};
