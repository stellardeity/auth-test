#include <QtNetwork>
#include <QtNetworkAuth>

#ifndef REPLAYHANDLER_H
#define REPLAYHANDLER_H


class CustomOAuthHandler : public QOAuthHttpServerReplyHandler
{
public:
    explicit CustomOAuthHandler(QObject *parent = nullptr);
//    CustomOAuthHandler(QObject *parent = nullptr);
    void callback();
    ~CustomOAuthHandler();
};

#endif // REPLAYHANDLER_H
