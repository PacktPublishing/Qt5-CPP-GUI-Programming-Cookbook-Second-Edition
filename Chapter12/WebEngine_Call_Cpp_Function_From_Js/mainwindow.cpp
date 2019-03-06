#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebChannel/QWebChannel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "1234");

    ui->setupUi(this);

    QWebEngineView* webview = new QWebEngineView();
    ui->verticalLayout->addWidget(webview);

    QWebChannel* webChannel = new QWebChannel();
    webChannel->registerObject("mainWindow", this);
    webview->page()->setWebChannel(webChannel);

    webview->page()->load(QUrl("qrc:///html/test.html"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeQtText(QString newText)
{
    ui->label->setText(newText);
}

void MainWindow::showLoginInfo(QString user, QString pass)
{
    QMessageBox::information(this, "Login info", "Username is " + user + " and password is " + pass);
}
