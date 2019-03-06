#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    hasInit = false;

    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("yourusername");
    db.setPassword("yourpassword");
    db.setDatabaseName("databasename");

    ui->tableWidget->setColumnHidden(0, true);

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec("SELECT id, name, age, gender, married FROM employee"))
        {
            while (query.next())
            {
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4);

                QString id = query.value(0).toString();
                QString name = query.value(1).toString();
                QString age = query.value(2).toString();
                int gender = query.value(3).toInt();
                bool married = query.value(4).toBool();

                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

                QTableWidgetItem* idItem = new QTableWidgetItem(id);
                QTableWidgetItem* nameItem = new QTableWidgetItem(name);
                QTableWidgetItem* ageItem = new QTableWidgetItem(age);
                QTableWidgetItem* genderItem = new QTableWidgetItem();

                if (gender == 0)
                    genderItem->setData(0, "Male");
                else
                    genderItem->setData(0, "Female");

                QTableWidgetItem* marriedItem = new QTableWidgetItem();

                if (married)
                    marriedItem->setData(0, "Yes");
                else
                    marriedItem->setData(0, "No");

                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, idItem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, nameItem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, ageItem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, genderItem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, marriedItem);
            }

            hasInit = true;
        }
        else
        {
            qDebug() << query.lastError().text();
        }
    }
    else
    {
        qDebug() << "Failed to connect to database.";
    }
}

MainWindow::~MainWindow()
{
    db.close();

    delete ui;
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if (hasInit)
    {
        QString id = ui->tableWidget->item(item->row(), 0)->data(0).toString();
        QString name = ui->tableWidget->item(item->row(), 1)->data(0).toString();
        QString age = QString::number(ui->tableWidget->item(item->row(), 2)->data(0).toInt());
        ui->tableWidget->item(item->row(), 2)->setData(0, age);

        QString gender;
        if (ui->tableWidget->item(item->row(), 3)->data(0).toString() == "Male")
        {
            gender = "0";
        }
        else
        {
            ui->tableWidget->item(item->row(), 3)->setData(0, "Female");
            gender = "1";
        }

        QString married;
        if (ui->tableWidget->item(item->row(), 4)->data(0).toString() == "No")
        {
            married = "0";
        }
        else
        {
            ui->tableWidget->item(item->row(), 4)->setData(0, "Yes");
            married = "1";
        }

        qDebug() << id << name << age << gender << married;

        QSqlQuery query;
        if (query.exec("UPDATE employee SET name = '" + name + "', age = '" + age + "', gender = '" + gender + "', married = '" + married + "' WHERE id = " + id))
        {
            QMessageBox::information(this, "Update Success", "Data updated to database.");
        }
        else
        {
            qDebug() << query.lastError().text();
        }
    }
}
