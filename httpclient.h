#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>

// Include needed Libraries
#include <QAbstractSocket>
#include <QTcpSocket>

const int TIMEOUT = 5000; // 5s, verwendet in scanner.cpp

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    // scan funktion
    // port muss quint16 sein weil das verlangt wird
    void scan(QString& host, quint16 port);

signals:
    // Sendet an Test Feld Widget
    void scanFinished(quint16 port, QString status);

public slots:
    void connected(QString& host);
    void readyRead();

private:
    QTcpSocket m_socket;
};

#endif // HTTPCLIENT_H
