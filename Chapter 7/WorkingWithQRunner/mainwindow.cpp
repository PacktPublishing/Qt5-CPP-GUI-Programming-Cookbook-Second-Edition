#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	MyProcess* process = new MyProcess;
	MyProcess* process2 = new MyProcess;
	MyProcess* process3 = new MyProcess;
	MyProcess* process4 = new MyProcess;

	QThreadPool::globalInstance()->start(process);
	QThreadPool::globalInstance()->start(process2);
	QThreadPool::globalInstance()->start(process3);
	QThreadPool::globalInstance()->start(process4);

	qDebug() << QThreadPool::globalInstance()->activeThreadCount();
	this->thread()->sleep(3);
	qDebug() << QThreadPool::globalInstance()->activeThreadCount();
}

MainWindow::~MainWindow()
{
	delete ui;
}
