#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void printMessage(QString message);

private slots:
	void on_connectButton_clicked();
	void on_sendButton_clicked();

	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();

private:
	Ui::MainWindow *ui;

	bool connectedToHost = false;
	QTcpSocket* socket;
};

#endif // MAINWINDOW_H
