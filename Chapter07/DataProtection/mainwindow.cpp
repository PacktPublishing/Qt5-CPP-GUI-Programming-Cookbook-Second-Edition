#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	int myNumber = 5;
	QMutex* newMutex = new QMutex;

	QThread* workerThread = new QThread;
	QThread* workerThread2 = new QThread;
	QThread* workerThread3 = new QThread;
	MyWorker *workerObject = new MyWorker(newMutex);
	MyWorker *workerObject2 = new MyWorker(newMutex);
	MyWorker *workerObject3 = new MyWorker(newMutex);

	workerObject->myInputNumber = &myNumber;
	workerObject->moveToThread(workerThread);
	connect(workerThread, &QThread::started, workerObject, &MyWorker::process);
	connect(workerObject, &MyWorker::doneProcess, workerThread, &QThread::quit);
	connect(workerObject, &MyWorker::doneProcess, workerObject, &MyWorker::deleteLater);
	connect(workerObject, &MyWorker::showResults, this, &MainWindow::handleResults);
	connect(workerThread, &QThread::finished, workerObject, &MyWorker::deleteLater);

	workerObject2->myInputNumber = &myNumber;
	workerObject2->moveToThread(workerThread2);
	connect(workerThread2, &QThread::started, workerObject2, &MyWorker::process);
	connect(workerObject2, &MyWorker::doneProcess, workerThread2, &QThread::quit);
	connect(workerObject2, &MyWorker::doneProcess, workerObject2, &MyWorker::deleteLater);
	connect(workerObject2, &MyWorker::showResults, this, &MainWindow::handleResults);
	connect(workerThread2, &QThread::finished, workerObject2, &MyWorker::deleteLater);

	workerObject3->myInputNumber = &myNumber;
	workerObject3->moveToThread(workerThread3);
	connect(workerThread3, &QThread::started, workerObject3, &MyWorker::process);
	connect(workerObject3, &MyWorker::doneProcess, workerThread3, &QThread::quit);
	connect(workerObject3, &MyWorker::doneProcess, workerObject3, &MyWorker::deleteLater);
	connect(workerObject3, &MyWorker::showResults, this, &MainWindow::handleResults);
	connect(workerThread3, &QThread::finished, workerObject3, &MyWorker::deleteLater);

	workerThread->start();
	workerThread2->start();
	workerThread3->start();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::handleResults(int res)
{
	qDebug() << "Final result:" << res;
}
