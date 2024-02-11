#include <QApplication>

#include <keycloakoidchandler.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    KeycloakOidcHandler keyclaok;
    keyclaok.auth();

    return a.exec();
}
