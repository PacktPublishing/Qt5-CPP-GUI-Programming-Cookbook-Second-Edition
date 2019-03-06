#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "1234");

    ui->setupUi(this);

    webview = new QWebEngineView();
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

void MainWindow::on_changeHtmlTextButton_clicked()
{
    webview->page()->runJavaScript("changeHtmlText('Text has been replaced by C++!');");
}

void MainWindow::on_playUIAnimationButton_clicked()
{
    webview->page()->runJavaScript("startAnim();");
}
