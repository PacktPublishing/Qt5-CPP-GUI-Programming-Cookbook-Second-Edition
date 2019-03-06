#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//QThread* workerThread = new QThread;
	MyWorker *workerObject = new MyWorker;

	//workerObject->moveToThread(workerThread);
	//connect(workerThread, &QThread::started, workerObject, &MyWorker::process);
	//connect(workerObject, &MyWorker::doneProcess, workerThread, &QThread::quit);
	connect(workerObject, &MyWorker::doneProcess, workerObject, &MyWorker::deleteLater);
	connect(workerObject, &MyWorker::showResults, this, &MainWindow::handleResults);
	//connect(workerThread, &QThread::finished, workerObject, &MyWorker::deleteLater);
	//workerThread->start();

	workerObject->process();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::handleResults(int res)
{
	qDebug() << "Final result:" << res;
}
