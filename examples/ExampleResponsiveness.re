[@react.component]
let make = () => {
    <Responsive>
        <MobileView>
            <div>("mobile" -> React.string)</div>
        </MobileView>
        <TabletView>
            <div>("tablet" -> React.string)</div>
        </TabletView>
        <DesktopView>
            <div>("desktop" -> React.string)</div>
        </DesktopView>
    </Responsive>
}