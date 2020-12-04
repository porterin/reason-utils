open Belt.Option;

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "error"] `Error
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "textPrimary"] `TextPrimary
  | [@bs.as "textSecondary"] `TextSecondary
];

[@bs.deriving jsConverter]
type fontSize = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "small"] `Small
  | [@bs.as "large"] `Large
];

[@bs.obj]
external makePropsIcon:
  (
    ~className: string=?,
    ~color: string=?,
    ~fontSize: string=?,
    ~nativeColor: string=?,
    ~titleAccess: string=?,
    ~viewBox: string=?,
    unit
  ) =>
  _ =
  "";

module type IconClass = {let reactClass: React.component('a);};

module Make = (Icon: IconClass) => {
  include Icon;

  [@react.component]
  let make =
      (
        ~color: option(color)=?,
        ~className: option(string)=?,
        ~fontSize: option(fontSize)=?,
        ~nativeColor: option(string)=?,
        ~titleAccess: option(string)=?,
        ~viewBox: option(string)=?,
      ) =>
    React.createElement(
      reactClass,
      makePropsIcon(
        ~className?,
        ~color=?color->map(colorToJs),
        ~fontSize=?fontSize->map(fontSizeToJs),
        ~nativeColor?,
        ~titleAccess?,
        ~viewBox?,
        (),
      ),
    );
};
