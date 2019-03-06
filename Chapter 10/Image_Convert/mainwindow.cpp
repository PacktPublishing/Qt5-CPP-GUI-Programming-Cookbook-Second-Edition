#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    ui->filePath->setText(fileName);
}

void MainWindow::on_convertButton_clicked()
{
    QString fileName = ui->filePath->text();

    if (fileName != "")
    {
        QFileInfo fileInfo = QFile(fileName);
        QString newFileName = fileInfo.path() + "/" + fileInfo.completeBaseName();

        QImage image = QImage(ui->filePath->text());

        if (!image.isNull())
        {
            // 0 - PNG
            // 1 - JPG
            // 2 - BMP
            int format = ui->fileFormat->currentIndex();
            if (format == 0)
            {
                newFileName += ".png";
            }
            else if (format == 1)
            {
                newFileName += ".jpg";
            }
            else if (format == 2)
            {
                newFileName += ".bmp";
            }

            qDebug() << newFileName << format;

            if (image.save(newFileName, 0, -1))
            {
                QMessageBox::information(this, "Success", "Image successfully converted.");
            }
            else
            {
                QMessageBox::warning(this, "Failed", "Failed to convert image.");
            }
        }
        else
        {
            QMessageBox::warning(this, "Failed", "Failed to open image file.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Failed", "No file is selected.");
    }
}
