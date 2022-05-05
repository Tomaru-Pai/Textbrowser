#include "gui.h"
#include "httpclient.h"
// httpsclient.h includieren, damit man damit interagieren kann
// Dasselbe, wie auch eine private: scanner bei widget.h !!!
// Für Popup ausgabe
#include <QDebug>
#include <QCoreApplication>

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    // m_socket = new QTcpSocket(this);

    // Signal ->  Slot-Verbindung
    connect(&m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(&m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);
}

void Gui::on_goButton_clicked()
{
    // Stelle verbindung mit den Widget Values auf
    // -> sind Pointer
    QString host = hostEntry->text();
    // Man bekommt einen String als wert, dieser muss umgewandelt werden
    // toUShort = to unsigned short
    quint16 port = 80; // HTTP Port

    // Funktion für Scan wird ausgeführt
    m_scanner.scan(host, port);
}

void showResult(quint16 port, QString status)
{

}

