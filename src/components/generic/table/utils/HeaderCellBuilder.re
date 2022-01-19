let execute = (~columnHeader: TableSchema.t('a), ~index: int) => {
    switch (columnHeader.column) {
    | Text(text) =>
    <MaterialUi.TableCell key={index->string_of_int}>
        {React.string(text)}
    </MaterialUi.TableCell>
    | Custom(renderFn) =>
    <MaterialUi.TableCell key={index->string_of_int}> {renderFn()} </MaterialUi.TableCell>
    }
}