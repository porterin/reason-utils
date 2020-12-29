type columnAccessor('a) = 'a => TableCell.t;

type t('a) = {
  column: TableColumnHeader.t,
  accessor: columnAccessor('a),
};
