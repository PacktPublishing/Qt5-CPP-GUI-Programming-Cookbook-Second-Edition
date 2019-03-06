#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include <QtSvg/QSvgGenerator>
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

    virtual void paintEvent(QPaintEvent *event);
    void paintAll(QSvgGenerator *generator = 0);

private slots:
    void on_actionSave_as_SVG_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
