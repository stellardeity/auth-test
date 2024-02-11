#include <QtNetwork>
#include <QtNetworkAuth>

#include <replayHandler.h>

CustomOAuthHandler::CustomOAuthHandler(QObject *parent):
    QOAuthHttpServerReplyHandler(parent)
{

}

//QString CustomOAuthHandler::callback() const
//{
//    Q_D(const QOAuthHttpServerReplyHandler);

//    const QUrl url(QString::fromLatin1("loh"));
//    return url.toString(QUrl::EncodeDelimiters);
//}


//CustomOAuthHandler::CustomOAuthHandler(QObject *parent) :
//    QOAuthHttpServerReplyHandler(parent)
//{

//}

CustomOAuthHandler::~CustomOAuthHandler()
{

}


void CustomOAuthHandler::callback()
{
    qDebug("test");
}
