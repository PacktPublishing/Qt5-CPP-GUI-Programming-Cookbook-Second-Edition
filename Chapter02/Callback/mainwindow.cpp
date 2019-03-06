#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->setMouseTracking(true);
	ui->centralWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	qDebug() << "Old size:" << event->oldSize() << ", New size:" << event->size();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Escape)
	{
		this->close();
	}

	qDebug() << event->text() << "has been pressed";
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	qDebug() << event->text() << "has been released";
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << "Position: " << event->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "Mouse pressed:" << event->button();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "Mouse released:" << event->button();
}
