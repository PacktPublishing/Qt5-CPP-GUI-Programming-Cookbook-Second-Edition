#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	webview = new QWebEngineView;
	ui->verticalLayout_2->addWidget(webview);

	//webview->page()->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, false);
	//webview->page()->settings()->setAttribute(QWebEngineSettings::AutoLoadImages, false);

    //QString fontFamily = webview->page()->settings()->fontFamily(QWebEngineSettings::SerifFont);
	QString fontFamily = webview->page()->settings()->fontFamily(QWebEngineSettings::SansSerifFont);
    int fontSize = webview->page()->settings()->fontSize(QWebEngineSettings::MinimumFontSize);
    QFont myFont = QFont(fontFamily, fontSize);
	webview->page()->settings()->setFontFamily(QWebEngineSettings::StandardFont, myFont.family());

	QFile file(":/tux.png");
    if (file.open(QFile::ReadOnly))
    {
		QByteArray data = file.readAll();
		webview->page()->setContent(data, "image/png");
    }
    else
    {
        qDebug() << "File cannot be opened.";
    }

    connect(webview, QWebEngineView::loadStarted, this, MainWindow::startLoading);
    connect(webview, QWebEngineView::loadProgress, this, MainWindow::loading);
	connect(webview, QWebEngineView::loadFinished, this, MainWindow::loaded);
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

void MainWindow::startLoading()
{
    ui->progressBar->show();
}

void MainWindow::loading(int progress)
{
    ui->progressBar->setValue(progress);
}

void MainWindow::loaded(bool ok)
{
	ui->progressBar->hide();
}

void MainWindow::on_loadHtml_clicked()
{
    webview->setHtml(ui->source->toPlainText());
}
