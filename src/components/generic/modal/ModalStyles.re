let getAlignContentCenterStyle = (~min_width="50%", ()) => {
  "overlay": {
    zIndex: 2,
    backgroundColor: "rgba(0, 0, 0, 0.40)",
  },
  "content": {
    top: "50%",
    left: "50%",
    right: "auto",
    bottom: "auto",
    marginRight: "-50%",
    transform: "translate(-50%, -50%)",
    minWidth: min_width,
    padding: "0",
  },
};
