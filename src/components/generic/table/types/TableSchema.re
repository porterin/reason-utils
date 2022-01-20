type columnAccessor('a) = 'a => TableCell.t;

type t('a) = {
  column: TableColumn.t,
  accessor: columnAccessor('a),
};
