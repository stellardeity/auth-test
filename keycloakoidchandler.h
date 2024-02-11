#include <QObject>

#ifndef KEYCLOAKOIDCHANDLER_H
#define KEYCLOAKOIDCHANDLER_H

class KeycloakOidcHandler : public QObject
{
    Q_OBJECT
public:
    void auth();
};

#endif // KEYCLOAKOIDCHANDLER_H
