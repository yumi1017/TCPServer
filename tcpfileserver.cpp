#include "tcpfileserver.h"

#include <QDialogButtonBox>
#include <QHostAddress>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent),
    serverStatusLabel(new QLabel(QStringLiteral("伺服器端就緒"), this)),
    startButton(new QPushButton(QStringLiteral("接收"), this))
{
    auto *serverProgressBar = new QProgressBar(this);
    serverProgressBar->setRange(0, 100);
    serverProgressBar->setValue(0);
    serverProgressBar->setTextVisible(false);

    auto *quitButton = new QPushButton(QStringLiteral("退出"), this);
    auto *buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);

    setWindowTitle(QStringLiteral("接收檔案"));
    resize(300, 140);

    connect(startButton, &QPushButton::clicked, this, &TcpFileServer::start);
    connect(quitButton, &QPushButton::clicked, this, &QWidget::close);
}

void TcpFileServer::start()
{
    if (!tcpServer.listen(QHostAddress::AnyIPv4, 16998)) {
        serverStatusLabel->setText(
            QStringLiteral("監聽失敗：%1").arg(tcpServer.errorString()));
        return;
    }

    serverStatusLabel->setText(QStringLiteral("監聽中..."));
    startButton->setEnabled(false);
}