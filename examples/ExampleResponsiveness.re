[@react.component]
let make = () => {
    <Responsive>
        <DesktopView>
            <ScrollableV2 height="100vh" onScrollEndCallback={ _ => ()}>
            <div style=(ReactDOMRe.Style.make(~height="100rem", ()))>("desktop" -> React.string)</div>
            </ScrollableV2>
        </DesktopView>
        <TabletView>
            <div>("tablet" -> React.string)</div>
        </TabletView>
        <MobileView>
            <div>("mobile" -> React.string)</div>
        </MobileView>
    </Responsive>
}