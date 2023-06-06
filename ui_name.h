/********************************************************************************
** Form generated from reading UI file 'name.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAME_H
#define UI_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Name
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Name)
    {
        if (Name->objectName().isEmpty())
            Name->setObjectName(QStringLiteral("Name"));
        Name->resize(921, 541);
        Name->setStyleSheet(QLatin1String("Name{\n"
"background-color: rgb(255, 240, 245);\n"
"}\n"
"\n"
"QPushButton{\n"
"border-radius:8px;\n"
"border: 2px solid rgb(163, 137, 131);\n"
"background-color: rgb(196, 170, 164);\n"
"	font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QPushButton::hover{\n"
"border: 2px solid rgb(163, 137, 131);\n"
"background-color: rgb(214, 186, 180);\n"
"}\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"/*background-color: rgb(212, 188, 181);*/\n"
"background-color: rgb(236, 215, 210);\n"
"border: 1px solid rgb(163, 137, 131);\n"
"}\n"
"QLineEdit{\n"
"font: 75 18pt \"Times New Roman\";\n"
"border: 2px solid rgb(163, 137, 131);\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(163, 137, 131);\n"
"}"));
        groupBox = new QGroupBox(Name);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 80, 801, 391));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 281, 61));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 210, 281, 61));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 100, 381, 61));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 210, 171, 61));
        pushButton = new QPushButton(Name);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(820, 10, 75, 23));
        pushButton_2 = new QPushButton(Name);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(820, 500, 75, 23));

        retranslateUi(Name);

        QMetaObject::connectSlotsByName(Name);
    } // setupUi

    void retranslateUi(QWidget *Name)
    {
        Name->setWindowTitle(QApplication::translate("Name", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Name", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\230\320\274\321\217 \320\270 \320\244\320\260\320\274\320\270\320\273\320\270\321\216:", nullptr));
        label_2->setText(QApplication::translate("Name", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\260 :", nullptr));
        lineEdit_2->setText(QString());
        pushButton->setText(QApplication::translate("Name", "Exit", nullptr));
        pushButton_2->setText(QApplication::translate("Name", "\320\224\320\260\320\273\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Name: public Ui_Name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAME_H
