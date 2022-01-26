#include "webclient.h"
#include <QDebug>

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(input, &QLineEdit::returnPressed, this, &Webclient::on_gobtn_clicked);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &Webclient::socketConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::printAndDisconnect);
}

void Webclient::outputMessage(QString message, QColor color)
{
    outputterminal->clear();
    outputterminal->setTextColor(color);
    outputterminal->setText(message);
}

void Webclient::socketConnected()
{

    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_search + "\r\n\r\n").toLocal8Bit());

}

void Webclient::printAndDisconnect()
{
    qDebug()<<"connected";
    outputMessage(m_socket->readAll());
    m_socket->disconnectFromHost();
}

void Webclient::on_gobtn_clicked()
{
    //m_socket->reset();
    if(input->text().isEmpty())
    {
        outputMessage("No such adress found");
    }
    else
    {
        m_socket->connectToHost(input->text(), m_port);
    }
}
