open IconBinding;

module ExpandMoreIcon =
  Make({
    [@bs.module "@material-ui/icons/ExpandMore"]
    external reactClass: React.component('a) = "default";
  });

module ExpandLessIcon =
  Make({
    [@bs.module "@material-ui/icons/ExpandLess"]
    external reactClass: React.component('a) = "default";
  });

module CloseIcon =
  Make({
    [@bs.module "@material-ui/icons/Close"] external reactClass: React.component('a) = "default";
  });

module NavigateIcon =
  Make({
    [@bs.module "@material-ui/icons/Launch"] external reactClass: React.component('a) = "default";
  });

module WarningIcon =
  Make({
    [@bs.module "@material-ui/icons/ReportProblemOutlined"]
    external reactClass: React.component('a) = "default";
  });

module PersonIcon =
  Make({
    [@bs.module "@material-ui/icons/Person"] external reactClass: React.component('a) = "default";
  });

module EditIcon =
  Make({
    [@bs.module "@material-ui/icons/EditOutlined"]
    external reactClass: React.component('a) = "default";
  });

module MoreVertIcon =
  Make({
    [@bs.module "@material-ui/icons/MoreVert"]
    external reactClass: React.component('a) = "default";
  });

module NavigateNextRoundedIcon =
  Make({
    [@bs.module "@material-ui/icons/NavigateNextRounded"]
    external reactClass: React.component('a) = "default";
  });

module KeyboardArrowUpIconIcon =
  Make({
    [@bs.module "@material-ui/icons/KeyboardArrowUp"]
    external reactClass: React.component('a) = "default";
  });

module KeyboardArrowDownIconIcon =
  Make({
    [@bs.module "@material-ui/icons/KeyboardArrowDown"]
    external reactClass: React.component('a) = "default";
  });

module ArrowBackIcon =
  Make({
    [@bs.module "@material-ui/icons/ArrowBackIos"]
    external reactClass: React.component('a) = "default";
  });

module AccountIcon =
  Make({
    [@bs.module "@material-ui/icons/AccountCircle"]
    external reactClass: React.component('a) = "default";
  });
