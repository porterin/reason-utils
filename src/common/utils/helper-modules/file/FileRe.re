type t;

[@bs.deriving abstract]
type fileOptions = {
  [@bs.as "type"]
  file_type: string,
};

/* ADD any required file types here */
let getFileExtensionFromType = (fileType: string) =>
  switch (fileType) {
  | "image/jpeg"
  | "image/jpg" => "jpg"
  | "image/png" => "png"
  | _ => failwith("file type not found")
  };

[@bs.new] external createFromBlob: (array(BlobRe.t), string, option(fileOptions)) => t = "File";

let create_from_blob = (blob: BlobRe.t, fileName: string) =>
  createFromBlob(
    [|blob|],
    String.concat(".", [fileName, getFileExtensionFromType(BlobRe.type_Get(blob))]),
    Some(fileOptions(~file_type=BlobRe.type_Get(blob))),
  );
