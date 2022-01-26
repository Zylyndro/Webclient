#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpSocket>

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);

private slots:
    void on_gobtn_clicked();

private:
    void outputMessage(QString message, QColor color = QColor::fromRgb(255, 0, 255));
    void socketConnected();
    void printAndDisconnect();

private:
    QTcpSocket *m_socket = nullptr;
    QString m_search;
    const char m_port = 80;
};

#endif // WEBCLIENT_H
