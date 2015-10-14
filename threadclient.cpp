#include "threadclient.h"

ThreadClient::ThreadClient()
{

    this->socket = new QTcpSocket();
    connect(this->socket, SIGNAL(readyRead()),this,SLOT(readData()));// récupérations des données lorsqu'elles arrivent dans la socket
    this->socket->connectToHost(QHostAddress::LocalHost,4444);// connection au serveur
}

void ThreadClient::readData()
{
    QString s;
    while(socket->bytesAvailable() > 0) {
        QString result = socket->readLine();
        s += result;
    }

    qDebug()<<s;

}
