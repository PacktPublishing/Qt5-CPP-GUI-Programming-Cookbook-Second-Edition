#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadXmlButton_clicked();

    void on_saveXmlButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
