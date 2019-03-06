#include <QCoreApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QDebug>

void filterAge()
{
    qDebug() << "== Employees above 30 year old =============";

    QSqlQuery query;
    if (query.exec("SELECT name, age FROM employee WHERE age > 30"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString() << query.value(1).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void getDepartmentAndBranch()
{
    qDebug() << "== Get employees' department and branch =============";

    QSqlQuery query;
    if (query.exec("SELECT myEmployee.name, department.name, branch.name FROM (SELECT name, departmentID FROM employee) AS myEmployee INNER JOIN department ON department.id = myEmployee.departmentID INNER JOIN branch ON branch.id = department.branchID"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString() << query.value(1).toString() << query.value(2).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void filterBranchAndAge()
{
    qDebug() << "== Employees from New York and age below 30 =============";

    QSqlQuery query;
    if (query.exec("SELECT myEmployee.name, myEmployee.age, department.name, branch.name FROM (SELECT name, age, departmentID FROM employee) AS myEmployee INNER JOIN department ON department.id = myEmployee.departmentID INNER JOIN branch ON branch.id = department.branchID WHERE branch.name = 'New York' AND age < 30"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString() << query.value(1).toString() << query.value(2).toString() << query.value(3).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void countFemale()
{
    qDebug() << "== Count female employees =============";

    QSqlQuery query;
    if (query.exec("SELECT COUNT(gender) FROM employee WHERE gender = 1"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void filterName()
{
    qDebug() << "== Employees name start with 'Ja' =============";

    QSqlQuery query;
    if (query.exec("SELECT name FROM employee WHERE name LIKE '%Ja%'"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void filterBirthday()
{
    qDebug() << "== Employees birthday in August =============";

    QSqlQuery query;
    if (query.exec("SELECT name, birthday FROM employee WHERE MONTH(birthday) = 8"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString() << query.value(1).toDate().toString("d-MMMM-yyyy");
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

void checkLog()
{
    qDebug() << "== Employees who logged in on 27 April 2016 =============";

    QSqlQuery query;
    if (query.exec("SELECT DISTINCT myEmployee.name FROM (SELECT id, name FROM employee) AS myEmployee INNER JOIN user ON user.employeeID = myEmployee.id INNER JOIN log ON log.userID = user.id WHERE DATE(log.loginTime) = '2016-04-27'"))
    {
        while (query.next())
        {
            qDebug() << query.value(0).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    qDebug() << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("reonyx");
    db.setPassword("reonyx");
    db.setDatabaseName("testing");

    if (db.open())
    {
        filterAge();
        getDepartmentAndBranch();
        filterBranchAndAge();
        countFemale();
        filterName();
        filterBirthday();
        checkLog();

        db.close();
    }
    else
    {
        qDebug() << "Failed to connect to database.";
    }

    return a.exec();
}
