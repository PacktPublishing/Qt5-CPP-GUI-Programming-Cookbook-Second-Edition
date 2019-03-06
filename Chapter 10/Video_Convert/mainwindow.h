#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QScrollBar>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QProcess* process;
    QString outputText;

    QString fileName;
    QString outputFileName;

private slots:
    void on_browseButton_clicked();
    void on_convertButton_clicked();

    void processStarted();
    void readyReadStandardOutput();
    void processFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
