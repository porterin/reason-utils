[@bs.val] [@bs.scope ("window", "navigator")] external clipboardSupported : bool = "clipboard";
[@bs.val] [@bs.scope ("window", "navigator", "clipboard")] external clipboardWriteText : string => Promise.t(unit) = "writeText";

let copyWithExecCommand : string => unit = [%bs.raw {|
  function(text) {
    var textField = document.createElement('textarea');
    textField.innerText = text;
    document.body.appendChild(textField);
    textField.select();
    document.execCommand('copy');
    textField.remove();
  }
|}];

let copy = (~text: string, ~onCopy: unit => unit) => {
  (clipboardSupported  ? 
    text -> clipboardWriteText : Promise.resolved(copyWithExecCommand(text))) -> Promise.get(_ => onCopy())
};

let useCopyToClipboard = (~text: string, ~children: React.element) => {
  let (copied, setCopied) = React.useState(() => false);
  (
    <div onClick={ _ => copy(~text, ~onCopy=(_ => setCopied(_ => true)))}>
      children
    </div>,
    copied,
    setCopied
  )
}