#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>
#include <QTcpServer>

class QLabel;
class QPushButton;

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileServer(QWidget *parent = nullptr);

private slots:
    void start();

private:
    QTcpServer tcpServer;
    QLabel *serverStatusLabel;
    QPushButton *startButton;
};

#endif