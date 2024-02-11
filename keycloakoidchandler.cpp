#include <QDesktopServices>
#include <QtNetwork>
#include <QtNetworkAuth>
#include <keycloakoidchandler.h>

void KeycloakOidcHandler::auth()
{

    auto keycloak = new QOAuth2AuthorizationCodeFlow;

    connect(keycloak, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);

    const QUrl authUri("https://id.aerstal.ru/realms/test/protocol/openid-connect/auth");
    const QUrl clientId(QString("admin-cli"));
    const QUrl clientSecret("702fcSq78uyx2abg8F8SxnjWnY0fY2Za");
    const QUrl redirectUri("http://localhost:3000");
    const QUrl tokenUri("https://id.aerstal.ru/auth/realms/test/protocol/openid-connect/token");

    keycloak->setAuthorizationUrl(authUri.toString());
    keycloak->setClientIdentifier(clientId.toString());
    keycloak->setAccessTokenUrl(tokenUri.toString());
    keycloak->setClientIdentifierSharedKey(clientSecret.toString());
    keycloak->setScope("openid");

    keycloak->setModifyParametersFunction([](QAbstractOAuth::Stage stage, QVariantMap* parameters) {
        QString url = "http://localhost:3000";
        QString encodedUrl = QUrl::toPercentEncoding(url);

       (*parameters)["redirect_uri"] = encodedUrl;
    });

    auto replyHandler = new QOAuthHttpServerReplyHandler(1337, this);
    keycloak->setReplyHandler(replyHandler);

    keycloak->grant();

//     connect(replyHandler, &QNetworkReply::finished, this, &test::handleFinished);
}
