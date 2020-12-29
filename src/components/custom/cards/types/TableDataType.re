type t = {
  title: string,
  tableData: Loadable.t(list(RowDataType.t)),
  actionBtnTop: option(ActionButtonType.t),
  actionBtnBot: option(ActionButtonType.t),
}
