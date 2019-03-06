#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QGridLayout *layout = new QGridLayout(ui->centralWidget);

	QTime* time = new QTime;
	time->start();

	// Test widget
	for (int i = 0; i < 40; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			QPushButton* newWidget = new QPushButton();
			newWidget->setText("Button");
			newWidget->setStyleSheet("background-color: blue; color: white;");
			layout->addWidget(newWidget, i, j);

			connect(newWidget, QPushButton::clicked,
			[this]()
			{
				QMessageBox::information(this, "Clicked", "Button has been clicked!");
			});
		}
	}
	qDebug() << "Test GUI:" << time->elapsed() << "msec";
}

MainWindow::~MainWindow()
{
	delete ui;
}
