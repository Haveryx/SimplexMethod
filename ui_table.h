/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QPushButton *pushButton_2;
    QPushButton *Optimal;
    QPushButton *NotOptimal;
    QPushButton *SomeSolution;

    void setupUi(QWidget *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QStringLiteral("Table"));
        Table->resize(762, 496);
        Table->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:8px;\n"
"border: 2px solid rgb(132, 139, 97);\n"
"background-color: rgb(132, 139, 97);\n"
"	font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QPushButton::hover{\n"
"border: 2px solid rgb(51, 107, 83);\n"
"background-color: rgb(117, 174, 143);\n"
"}\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"background-color: rgb(212, 188, 181);\n"
"}\n"
"QLineEdit{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}"));
        pushButton_2 = new QPushButton(Table);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(680, 0, 75, 23));
        Optimal = new QPushButton(Table);
        Optimal->setObjectName(QStringLiteral("Optimal"));
        Optimal->setGeometry(QRect(39, 0, 161, 41));
        NotOptimal = new QPushButton(Table);
        NotOptimal->setObjectName(QStringLiteral("NotOptimal"));
        NotOptimal->setGeometry(QRect(260, 0, 171, 41));
        SomeSolution = new QPushButton(Table);
        SomeSolution->setObjectName(QStringLiteral("SomeSolution"));
        SomeSolution->setGeometry(QRect(440, 0, 241, 41));

        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QWidget *Table)
    {
        Table->setWindowTitle(QApplication::translate("Table", "Form", nullptr));
        pushButton_2->setText(QApplication::translate("Table", "Exit", nullptr));
        Optimal->setText(QApplication::translate("Table", "\320\236\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        NotOptimal->setText(QApplication::translate("Table", "\320\235\320\265 \320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        SomeSolution->setText(QApplication::translate("Table", "\320\225\321\201\321\202\321\214 \320\265\321\211\320\265 \320\276\320\264\320\275\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
