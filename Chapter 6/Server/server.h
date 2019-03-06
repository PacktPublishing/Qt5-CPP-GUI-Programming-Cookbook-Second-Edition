#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>

class server : public QObject
{
	Q_OBJECT
public:
	server(QObject *parent = nullptr);
	void startServer();
	void sendMessageToClients(QString message);

signals:

public slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadReady();
	void socketStateChanged(QAbstractSocket::SocketState state);

private:
	QTcpServer* chatServer;
	QVector<QTcpSocket*>* allClients;
};

#endif // SERVER_H
