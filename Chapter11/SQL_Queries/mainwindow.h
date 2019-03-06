#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
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

private slots:
    void on_updateButton_clicked();
    void on_insertButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    bool connected;
    int currentID;
};

#endif // MAINWINDOW_H
