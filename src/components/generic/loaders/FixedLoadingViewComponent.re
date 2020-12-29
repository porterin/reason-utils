[@react.component]
let make = (~text="Loading") => {
  <div className="fixed-loader-section">
    <LoadingViewComponent text />
  </div>
}
