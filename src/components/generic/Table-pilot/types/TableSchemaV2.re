type columnAccessor('a) = 'a => TableCell.t;

type t('a) = {
  column: TableColumnHeader.t,
  accessor: columnAccessor('a),
  is_visible_only_on_hover: bool,
};

let make_props =
    (
      ~column: TableColumnHeader.t,
      ~accessor: columnAccessor('a),
      ~is_visible_only_on_hover: bool=false,
      (),
    )
    : t('a) => {
  column,
  accessor,
  is_visible_only_on_hover,
};
