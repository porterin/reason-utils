open Jest;

open PrimitiveFormTypes;

let () =
  describe(
    "#getValue",
    ExpectJs.(
      () => {
        test("get value from input type", () =>
          expect(PrimitiveFormTypes.getValue(String("test string")))
          |> toEqual(Ok("test string"))
        );
      }
    ),
  );
