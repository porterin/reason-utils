let generatePenaltyListRedirectLink = (href: string) => {
  Env.getHostName() ++ href;
};

[@react.component]
let make = (~title: string, ~link: string) => {
  <Row>
    <Icon.NavigateIcon fontSize=`Default />
    <a className="redirect-link" target="_blank" href={generatePenaltyListRedirectLink(link)}>
      {React.string(title)}
    </a>
  </Row>;
};
