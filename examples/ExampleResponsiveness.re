[@react.component]
let make = () => {
    let (open_, setOpen) = React.useState(_ => true);
    <Responsive>
        <DesktopView>
            <Scrollable height="100vh" onScrollEndCallback={ _ => ()}>
                <div style=(ReactDOMRe.Style.make(~height="100rem", ()))>
                   {React.string("dfdf")}
                   <DateRangePicker open_  toggle={_ => setOpen(_ => !open_)} onChange={e => Js.log(e)}/>
                </div>
            </Scrollable>
        </DesktopView>
        <TabletView>
            <div>("tablet" -> React.string)</div>
        </TabletView>
        <MobileView>
            <div>("mobile" -> React.string)</div>
        </MobileView>
    </Responsive>
}