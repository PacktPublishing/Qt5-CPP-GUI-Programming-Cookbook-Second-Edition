#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webview = new QWebEngineView;
    ui->horizontalLayout_2->addWidget(webview);

    connect(webview, QWebEngineView::loadProgress, this, MainWindow::loading);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadUrl()
{
    QUrl url = QUrl(ui->address->text());
    url.setScheme("http");
    webview->page()->load(url);
}

void MainWindow::on_goButton_clicked()
{
    loadUrl();
}

void MainWindow::on_address_returnPressed()
{
    loadUrl();
}

void MainWindow::on_backButton_clicked()
{
    webview->back();
}

void MainWindow::on_forwardButton_clicked()
{
    webview->forward();
}

void MainWindow::loading(int progress)
{
    ui->progressBar->setValue(progress);
}
