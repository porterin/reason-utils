[@react.component]
let make = () => {
    <Responsive>
        <DesktopView>
            <div>("desktop" -> React.string)</div>
        </DesktopView>
        <TabletView>
            <div>("tablet" -> React.string)</div>
        </TabletView>
        <MobileView>
            <div>("mobile" -> React.string)</div>
        </MobileView>
    </Responsive>
}