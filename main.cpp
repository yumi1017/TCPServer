#include "tcpfileserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TcpFileServer server;
    server.show();
    return app.exec();
}