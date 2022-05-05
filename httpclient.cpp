#include "httpclient.h"
#include <QDebug>
#include <QCoreApplication>

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{

}

void HttpClient::scan(QString& host, quint16 port)
{
    bool status = false; // Default immer auf 0
    // bool = 0 oder 1

    // Verbindung wird hergestellt
    m_socket.connectToHost(host, port);

    // Prüft obverbindung hergestellt werden kann
    // TIMEOUT: globale Variable
    if (m_socket.waitForConnected(TIMEOUT)) {
        // Trennt verbindung
        m_socket.disconnectFromHost();
        // Meldet, dass verbindung hergestellt worden ist
        status = true;
    }
}

void HttpClient::connected(QString& host)
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + host + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server
    qDebug() << m_socket->readAll();
    m_socket->disconnectFromHost();
    QCoreApplication::quit();
}



