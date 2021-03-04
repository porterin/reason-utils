let createViewFromList = (list: list(string), seperator: string) => {
  let newList =
    switch (list) {
    | [_item, ...lst] => lst
    | [] => []
    };
  List.fold_left(
    (viewString, listItem) => viewString ++ seperator ++ " " ++ listItem,
    List.nth(list, 0),
    newList,
  );
};

let extractLiveData = (loadableData: FetchLoadable.t('a)): option('a) => {
  switch (loadableData) {
  | Live(data) => Some(data)
  | _ => None
  };
};

let resolveEmptyText = (~resolveAs="", text) => {
  switch (text) {
  | None => resolveAs->CommonTypes.Text
  | Some(text) => text->CommonTypes.Text
  };
};

module CTAButtonHelper = {
  type t = {
    label: string,
    onSelectCB: unit => unit,
  };

  let getCtaButtons = (ctaBtnList: list(t)) => {
    ctaBtnList
    |> List.map((ctaBtn: t) =>
         <TertiaryButton
           className="text-styling-cat-items navbar__ctaListItem" onSelectCB={ctaBtn.onSelectCB}>
           {React.string(ctaBtn.label)}
         </TertiaryButton>
       );
  };
};

let toAmountString = (amt: float) => {
  let prefix = amt < 0.0 ? "-" : "";
  amt->Js.Math.abs_float->Js.Float.toString
  |> Js.String.replaceByRe([%re "/\B(?=(\d{3})+(?!\d))/g"], ",")
  |> (value => prefix ++ {j| ₹|j} ++ value);
};

let toAmountStringWithPrecision = (~digits=2, amt: float, ) => {
  let prefix = amt < 0.0 ? "-" : "";
  amt->Js.Math.abs_float-> Js.Float.toFixedWithPrecision(~digits)
  |> Js.String.replaceByRe([%re "/\B(?=(\d{3})+(?!\d))/g"], ",")
  |> (value => prefix ++ {j| ₹|j} ++ value);
}