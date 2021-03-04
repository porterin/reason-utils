[@bs.val] external node_env: string = "process.env.NODE_ENV";
[@bs.val] external oms_url: string = "process.env.OMS_URL";
[@bs.val] external crm_url: string = "window.location.origin";

let getHostName = (): string => {
  switch (node_env) {
  | "development" => "http://localhost:3000"
  | _ => oms_url
  };
};

let getWorkingEnv=() => {
  Environment.fromString(node_env)
}
