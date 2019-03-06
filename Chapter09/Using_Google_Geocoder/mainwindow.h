#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QXmlStreamReader>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_getAddressButton_clicked();
    void getAddressFinished(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager* addressRequest;
};

#endif // MAINWINDOW_H
