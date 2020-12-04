[@react.component]
let make =
    (
      ~img_src: string,
      ~webp_src: string,
      ~class_name: string="",
      ~img_type: string="image/png",
      ~alt_text: string="img",
    ) => {
  let showWebp = false;
  showWebp
    ? <picture>
        <source className=class_name srcSet=webp_src type_="image/webp" />
        <source className=class_name srcSet=img_src type_=img_type />
        <img className=class_name src=img_src alt=alt_text />
      </picture>
    : <img className=class_name srcSet=img_src />;
};
