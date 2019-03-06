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

void MainWindow::on_loadXmlButton_clicked()
{
    QDomDocument xml;

    QString filename = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Error loading XML file.";
    if (!xml.setContent(&file))
    {
        qDebug() << "Error setting content.";
        file.close();
        return;
    }
    file.close();

    QDomElement element = xml.documentElement();
    QDomNode node = element.firstChild();

    while(!node.isNull())
    {
        QDomElement nodeElement = node.toElement();
        if(!nodeElement.isNull())
        {
            if (nodeElement.tagName() == "object")
            {
                qDebug() << "[Object]=================================";

                QDomNode childNode = nodeElement.firstChild();

                while (!childNode.isNull())
                {
                    QDomElement childNodeElement = childNode.toElement();

                    QString name = childNodeElement.tagName();
                    if (name == "name" || name == "position" || name == "rotation" || name == "scale")
                    {
                        QString text = childNodeElement.text();
                        qDebug() << name << text;
                    }

                    childNode = childNode.nextSibling();
                }
            }

            qDebug() << "=========================================";
        }

        node = node.nextSibling();
    }
}

void MainWindow::on_saveXmlButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Xml", ".", "Xml files (*.xml)");
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Error saving XML file.";
        file.close();
        return;
    }

    QDomDocument xml("contact");

    // John Doe
    QDomElement root = xml.createElement("contact");
    root.setAttribute("category", "Family");
    xml.appendChild(root);

    QDomElement tagName = xml.createElement("name");
    root.appendChild(tagName);
    QDomText textName = xml.createTextNode("John Doe");
    tagName.appendChild(textName);

    QDomElement tagAge = xml.createElement("age");
    root.appendChild(tagAge);
    QDomText textAge = xml.createTextNode("32");
    tagAge.appendChild(textAge);

    QDomElement tagAddress = xml.createElement("address");
    root.appendChild(tagAddress);
    QDomText textAddress = xml.createTextNode("114B, 2nd Floor, Sterling Apartment, Morrisontown");
    tagAddress.appendChild(textAddress);

    QDomElement tagPhone = xml.createElement("phone");
    root.appendChild(tagPhone);
    QDomText textPhone = xml.createTextNode("0221743566");
    tagPhone.appendChild(textPhone);

    // Jane Smith
    QDomElement root2 = xml.createElement("contact");
    root2.setAttribute("category", "Friend");
    xml.appendChild(root2);

    QDomElement tagName2 = xml.createElement("name");
    root2.appendChild(tagName2);
    QDomText textName2 = xml.createTextNode("John Doe");
    tagName2.appendChild(textName2);

    QDomElement tagAge2 = xml.createElement("age");
    root2.appendChild(tagAge2);
    QDomText textAge2 = xml.createTextNode("24");
    tagAge2.appendChild(textAge2);

    QDomElement tagAddress2 = xml.createElement("address");
    root2.appendChild(tagAddress2);
    QDomText textAddress2 = xml.createTextNode("13, Ave Park, Alexandria");
    tagAddress2.appendChild(textAddress2);

    QDomElement tagPhone2 = xml.createElement("phone");
    root2.appendChild(tagPhone2);
    QDomText textPhone2 = xml.createTextNode("0025728396");
    tagPhone2.appendChild(textPhone2);

    // Save to file
    QTextStream output(&file);
    output << xml.toString();

    file.close();
}
