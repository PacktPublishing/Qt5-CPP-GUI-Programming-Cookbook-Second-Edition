#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void getFileList();

private slots:
	void on_openButton_clicked();
	void on_uploadButton_clicked();
	void on_setFolderButton_clicked();
	void on_fileList_itemDoubleClicked(QListWidgetItem *item);

	void downloadFileListFinished();
	void uploadFileListFinished();

	void uploadFileProgress(qint64 bytesSent, qint64 bytesTotal);
	void uploadFileFinished();

	void downloadFileProgress(qint64 byteReceived,qint64 bytesTotal);
	void downloadFileFinished();

private:
	Ui::MainWindow *ui;

	QNetworkAccessManager* manager;

	QString ftpAddress;
	int ftpPort;
	QString username;
	QString password;

	QNetworkReply* downloadFileListReply;
	QNetworkReply* uploadFileListReply;

	QNetworkReply* uploadFileReply;
	QNetworkReply* downloadFileReply;

	QStringList fileList;
	QString uploadFileName;
	QString downloadFileName;
};

#endif // MAINWINDOW_H
