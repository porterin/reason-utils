let getFileContent = (content: list(list(string))): string => {
  let rowsStringList = List.map(row => String.concat(",", row), content);
  let csvContent = "data:text/csv;charset=utf-8," ++ String.concat("\n", rowsStringList);
  JsBindings.encodeURI(csvContent);
};
