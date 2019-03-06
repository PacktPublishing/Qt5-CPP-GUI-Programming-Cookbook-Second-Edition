#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebChannel/QWebChannel>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWebEngineView* webview;

private slots:
    void on_changeHtmlTextButton_clicked();
    void on_playUIAnimationButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
