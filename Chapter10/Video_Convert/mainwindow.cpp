#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    process = new QProcess(this);
    connect(process, QProcess::started, this, MainWindow::processStarted);
    connect(process, QProcess::readyReadStandardOutput,this, MainWindow::readyReadStandardOutput);
    connect(process, QProcess::finished, this, MainWindow::processFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Video", "", "Video Files (*.avi *.mp4 *.mov)");
    ui->filePath->setText(fileName);
}

void MainWindow::on_convertButton_clicked()
{
    QString ffmpeg = "C:/FFmpeg/bin/ffmpeg";
    QStringList arguments;

    fileName = ui->filePath->text();
    if (fileName != "")
    {
        QFileInfo fileInfo = QFile(fileName);
        outputFileName = fileInfo.path() + "/" + fileInfo.completeBaseName();

        if (QFile::exists(fileName))
        {
            // 0 - AVI
            // 1 - MP4
            // 2 - MOV
            int format = ui->fileFormat->currentIndex();
            if (format == 0)
            {
                outputFileName += ".avi";
            }
            else if (format == 1)
            {
                outputFileName += ".mp4";
            }
            else if (format == 2)
            {
                outputFileName += ".mov";
            }

            qDebug() << outputFileName << format;

            arguments << "-i" << fileName << outputFileName;

            qDebug() << arguments;

            process->setProcessChannelMode(QProcess::MergedChannels);
            process->start(ffmpeg, arguments);
        }
        else
        {
            QMessageBox::warning(this, "Failed", "Failed to open video file.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Failed", "No file is selected.");
    }
}

void MainWindow::processStarted()
{
    qDebug() << "Process started.";

    ui->browseButton->setEnabled(false);
    ui->fileFormat->setEditable(false);
    ui->convertButton->setEnabled(false);
}

void MainWindow::readyReadStandardOutput()
{
    outputText += process->readAllStandardOutput();
    ui->outputDisplay->setText(outputText);

    ui->outputDisplay->verticalScrollBar()->setSliderPosition(ui->outputDisplay->verticalScrollBar()->maximum());
}

void MainWindow::processFinished()
{
    qDebug() << "Process finished.";

    if (QFile::exists(outputFileName))
    {
        QMessageBox::information(this, "Success", "Video successfully converted.");
    }
    else
    {
        QMessageBox::information(this, "Failed", "Failed to convert video.");
    }

    ui->browseButton->setEnabled(true);
    ui->fileFormat->setEditable(true);
    ui->convertButton->setEnabled(true);
}
