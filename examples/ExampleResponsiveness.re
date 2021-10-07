[@react.component]
let make = () => {
    <Responsive>
        <DesktopView>
            <ExampleTable />
        </DesktopView>
        <TabletView>
            <div>("tablet" -> React.string)</div>
        </TabletView>
        <MobileView>
            <div>("mobile" -> React.string)</div>
        </MobileView>
    </Responsive>
}