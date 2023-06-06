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
    QPushButton *pushButton;

    void setupUi(QWidget *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QStringLiteral("Table"));
        Table->resize(762, 496);
        Table->setStyleSheet(QLatin1String("Table{\n"
"background-color: rgb(255, 240, 245);\n"
"}\n"
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
"\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"/*background-color: rgb(212, 188, 181);*/\n"
"background-color: rgb(236, 215, 210);\n"
"border: 1px solid rgb(163, 137, 131);\n"
"}\n"
"QLineEdit{\n"
"font: 75 18pt \"Times New Roman\";\n"
"border: 2px solid rgb(163, 137, 131);\n"
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
        pushButton = new QPushButton(Table);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 251, 51));
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);

        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QWidget *Table)
    {
        Table->setWindowTitle(QApplication::translate("Table", "SimplexMethod", nullptr));
        pushButton_2->setText(QApplication::translate("Table", "Exit", nullptr));
        Optimal->setText(QApplication::translate("Table", "\320\236\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        NotOptimal->setText(QApplication::translate("Table", "\320\235\320\265 \320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        SomeSolution->setText(QApplication::translate("Table", "\320\225\321\201\321\202\321\214 \320\265\321\211\320\265 \320\276\320\264\320\275\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
        pushButton->setText(QApplication::translate("Table", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272  \n"
"\321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\274\321\203 \320\277\320\276\321\201\320\276\320\261\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
