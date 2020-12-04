open PrimitiveFormTypes;

module ExampleForm = [%form
  type input = {
    amount: string,
    comment: string,
    date: Js.Date.t,
    time: Js.Date.t,
    radio: string,
    select: option(SelectComponent.t),
    check: list(string),
    selectCheck: list(string),
  };
  type output = {
    amount: int,
    comment: string,
    date: Js.Date.t,
    time: Js.Date.t,
    radio: string,
    select: string,
    check: list(string),
    selectCheck: list(string),
  };
  let validators = {
    amount: {
      strategy: OnFirstBlur,
      validate: ({amount}) => {
        getValue(Int(amount))
        ->Belt.Result.flatMap(amount_i =>
            if (amount_i < 10) {
              Belt.Result.Error({js|Donations above the value of ₹ 10 are accepted|js});
            } else if (amount_i > 10000000) {
              Belt.Result.Error(
                {js|Donations below the value of ₹ 1,00,00,000 are accepted|js},
              );
            } else {
              Belt.Result.Ok(amount_i);
            }
          );
      },
    },
    comment: None,
    date: None,
    time: None,
    radio: {
      strategy: OnSubmit,
      validate: ({radio}) => {
        switch (radio) {
        | "" => Belt.Result.Error("Select a radio value")
        | value => Belt.Result.Ok(value)
        };
      },
    },
    select: {
      strategy: OnSubmit,
      validate: ({select}) => {
        switch (select) {
        | None => Belt.Result.Error("Please Select a value")
        | Some(item) => Belt.Result.Ok(item.value)
        };
      },
    },
    check: None,
    selectCheck: None,
  }
];

let radioItems: list(SelectComponent.t) = [
  {key: "key", value: "value", text: "text"},
  {key: "key2", value: "value2", text: "text2"},
];

let checkBoxItems: list(CheckBoxGroup.t) = [
  {id: "key", value: "value", label: "text"},
  {id: "key2", value: "value2", label: "text2"},
  {id: "key3", value: "value3", label: "text3"},
  {id: "key4", value: "value4", label: "text4"},
];

let selectCheckBoxItems: list(SelectWithCheckBoxes.t) = [
  {key: "1", value: "varun", text: "varun"},
  {
    key: "2",
    value: "karankarankarankarankarankarankarankarankarankaran",
    text: "karankarankarankarankarankarankarankarankarankaran",
  },
];

let getSelectedItem = (value: string): option(SelectComponent.t) => {
  List.exists((a: SelectComponent.t) => a.value === value, radioItems)
    ? Some(radioItems |> List.find((item: SelectComponent.t) => {item.value === value})) : None;
};

let isChecked = (selected: list(string), currentValue: string) => {
  let isSelected = ListUtils.find(selected, value => value == currentValue);
  switch (isSelected) {
  | Some(_isSelected) => true
  | None => false
  };
};

[@react.component]
let make = () => {
  let form =
    ExampleForm.useForm(
      ~initialInput=
        ExampleForm.{
          amount: "",
          comment: "",
          date: Js.Date.fromFloat(Js.Date.now()),
          time: Js.Date.fromFloat(Js.Date.now()),
          radio: "",
          select: None,
          check: [],
          selectCheck: [],
        },
      ~onSubmit=(
                  output: ExampleForm.output,
                  submissionCbs:
                    Formality.submissionCallbacks(ExampleForm.input, ExampleForm.submissionError),
                ) => {
        Js.log(output);
        /* Reset To reset the form */
        submissionCbs.reset();
        /* If you dont't reset and want to again submit form then use notifyOnSuccess */
        submissionCbs.notifyOnSuccess(None);
      },
    );

  <form onSubmit={form.submit->FormalityCompat.Dom.preventDefault}>
    <div className="example-form">
      <Row>
        <FormInput
          input_props={FormInput.make_props(
            ~label="Amount",
            ~onChange=
              event =>
                form.updateAmount(
                  (input, value) => {...input, amount: value},
                  event->FormHelper.TargetEventWrapper.value,
                ),
            ~placeholder="Enter amount",
            ~value={Input(form.input.amount)},
            ~result={form.amountResult},
            (),
          )}
        />
        <FormInput
          input_props={FormInput.make_props(
            ~label="Date",
            ~onChange=_ => (),
            ~value=
              {Date({
                 value: form.input.date,
                 minDate: None,
                 maxDate: None,
                 onChange: date =>
                   form.updateDate((input, value) => {...input, date: value}, date),
                 format: "dd/MM/YYYY",
               })},
            ~result={form.dateResult},
            (),
          )}
        />
        <FormInput
          input_props={FormInput.make_props(
            ~label="Comment",
            ~onChange=
              event =>
                form.updateAmount(
                  (input, value) => {...input, comment: value},
                  event->FormHelper.TargetEventWrapper.value,
                ),
            ~placeholder="Enter comment",
            ~value={Input(form.input.comment)},
            ~result={form.commentResult},
            (),
          )}
        />
      </Row>
      <Row>
        <FormInput
          input_props={FormInput.make_props(
            ~label="Time",
            ~onChange=_ => (),
            ~value=
              {Time({
                 value: form.input.time,
                 onChange: date =>
                   form.updateTime((input, value) => {...input, time: value}, date),
               })},
            ~result={form.timeResult},
            (),
          )}
        />
      </Row>
      <FormInput
        input_props={FormInput.make_props(
          ~label="Radio",
          ~onChange=
            event =>
              form.updateRadio(
                (input, value) => {...input, radio: value},
                event->FormHelper.TargetEventWrapper.value,
              ),
          ~value=
            {RadioGroup({
               value: form.input.radio,
               options: [
                 {label: "option1", value: "option1"},
                 {label: "option2", value: "option2"},
                 {label: "option3", value: "option3"},
               ],
               row_layout: true,
             })},
          ~result={form.radioResult},
          (),
        )}
      />
      <FormInput
        input_props={FormInput.make_props(
          ~label="Select",
          ~onChange=
            event =>
              form.updateSelect(
                (input, value) => {...input, select: value},
                event->FormHelper.TargetEventWrapper.value->getSelectedItem,
              ),
          ~value={Select({value: form.input.select, items: radioItems})},
          ~result={form.selectResult},
          (),
        )}
      />
      <FormInput
        input_props={FormInput.make_props(
          ~label="Check Box",
          ~onChange=
            event =>
              form.updateCheck(
                (input, value) => {...input, check: value},
                isChecked(form.input.check, event->FormHelper.TargetEventWrapper.value)
                  ? List.filter(
                      a => a != event->FormHelper.TargetEventWrapper.value,
                      form.input.check,
                    )
                  : [event->FormHelper.TargetEventWrapper.value, ...form.input.check],
              ),
          ~value=
            {CheckBox({selected: form.input.check, options: checkBoxItems, row_layout: true})},
          ~result={form.checkResult},
          (),
        )}
      />
      <FormInput
        input_props={FormInput.make_props(
          ~label="Select Check boxes",
          ~onChange=
            event => {
              form.updateSelectCheck(
                (input, value) => {...input, selectCheck: value},
                event->FormHelper.TargetListEventWrapper.listValue,
              )
            },
          ~value=
            {SelectCheckBoxes({
               selected: form.input.selectCheck,
               options: selectCheckBoxItems,
               renderValue: None,
             })},
          ~result={form.selectCheckResult},
          (),
        )}
      />
      <Row>
        <FormInput
          input_props={FormInput.make_props(
            ~label="Time",
            ~onChange=_ => (),
            ~value=
              {KeyInputTime({
                 value: form.input.time,
                 onChange: date =>
                   form.updateTime((input, value) => {...input, time: value}, date),
                 format: "hh:mm a",
                 invalidDateMessage: Some("Invalid time"),
               })},
            ~result={form.timeResult},
            (),
          )}
        />
      </Row>
      <button> {React.string("Submit")} </button>
    </div>
  </form>;
};
