#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("yourusername");
    db.setPassword("yourpassword");
    db.setDatabaseName("databasename");

    if (!db.open())
    {
        qDebug() << "Failed to connect to database.";
    }
}

MainWindow::~MainWindow()
{
    db.close();

    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query;
    if (query.exec("SELECT employeeID from user WHERE username = '" + username + "' AND password = '" + password + "'"))
    {
        if (query.size() > 0)
        {
            while (query.next())
            {
                QString employeeID = query.value(0).toString();

                QSqlQuery query2;
                if (query2.exec("SELECT name, age, gender, married FROM employee WHERE id = " + employeeID))
                {
                    while (query2.next())
                    {
                        QString name = query2.value(0).toString();
                        QString age = query2.value(1).toString();
                        int gender = query2.value(2).toInt();
                        bool married = query2.value(3).toBool();

                        ui->name->setText(name);
                        ui->age->setText(age);

                        if (gender == 0)
                            ui->gender->setText("Male");
                        else
                            ui->gender->setText("Female");

                        if (married)
                            ui->married->setText("Yes");
                        else
                            ui->married->setText("No");

                        ui->stackedWidget->setCurrentIndex(1);
                    }
                }
            }
        }
        else
        {
            QMessageBox::warning(this, "Login failed", "Invalid username or password.");
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }
}

void MainWindow::on_logoutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
