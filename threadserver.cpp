#include <QTimer>
#include "threadserver.h"

ThreadServer::ThreadServer()
{
    this->server = new QTcpServer();

    if (!server->listen(QHostAddress::LocalHost, 4444)) {
        qDebug() << "Unable to start the server";
        return;
    }
    QString ipAddress;
    ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << "address = " << server->serverAddress() << "\nport = " << server->serverPort();
    connect(server, SIGNAL(newConnection()), this, SLOT(newClient()));

    this->time = new QTimer();
     time->start(10000);
    connect(time,SIGNAL(timeout()),this,SLOT(emitSeason())); // losrque le timer réalise un tick, envoi le signal

}

void ThreadServer::run(){
    // TODO : attendre 5 minutes envoyer le signal (emit)


}

void ThreadServer::emitSeason()
{
    QString string = "changement";
    qDebug()<<"Serveur : changement de saison";
    std::for_each(this->clients.begin(), this->clients.end(), [string](QTcpSocket *s){
       s->write(string.toUtf8());
       s->flush();
    });
}

void ThreadServer::newClient()
{
    QTcpSocket *clientConnection = server->nextPendingConnection();
    clients.push_back(clientConnection);
    qDebug()<<"TServ : nouvelle conexion : "<<clientConnection->peerPort();
}

