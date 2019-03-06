#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QDebug>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void loadUrl();

private slots:
	void on_goButton_clicked();
	void on_address_returnPressed();
    void on_backButton_clicked();
    void on_forwardButton_clicked();

    void startLoading();
    void loading(int progress);
    void loaded(bool ok);

	void on_loadHtml_clicked();

private:
    Ui::MainWindow *ui;

    QWebEngineView* webview;
};

#endif // MAINWINDOW_H
