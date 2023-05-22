/********************************************************************************
** Form generated from reading UI file 'solution.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTION_H
#define UI_SOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Solution
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Solution)
    {
        if (Solution->objectName().isEmpty())
            Solution->setObjectName(QStringLiteral("Solution"));
        Solution->resize(737, 423);
        Solution->setStyleSheet(QLatin1String("Solution{\n"
"background-color: rgb(212, 188, 181);\n"
"}\n"
"QPushButton{\n"
"border-radius:8px;\n"
"border: 2px solid rgb(51, 81, 83);\n"
"background-color: rgb(155,93,86);\n"
"	font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QPushButton::hover{\n"
"border: 2px solid rgb(51, 107, 83);\n"
"background-color: rgb(152,143,250);\n"
"}\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QRadioButton{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(110,151,145);\n"
"\n"
"}\n"
"\n"
""));
        groupBox = new QGroupBox(Solution);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(560, 90, 161, 141));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        pushButton = new QPushButton(Solution);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 330, 241, 61));
        lineEdit = new QLineEdit(Solution);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(340, 120, 151, 31));
        lineEdit_2 = new QLineEdit(Solution);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(340, 160, 151, 31));
        label = new QLabel(Solution);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 291, 21));
        label_2 = new QLabel(Solution);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 160, 291, 31));

        retranslateUi(Solution);

        QMetaObject::connectSlotsByName(Solution);
    } // setupUi

    void retranslateUi(QWidget *Solution)
    {
        Solution->setWindowTitle(QApplication::translate("Solution", "Form", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("Solution", "Min", nullptr));
        radioButton_2->setText(QApplication::translate("Solution", "Max", nullptr));
        pushButton->setText(QApplication::translate("Solution", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label->setText(QApplication::translate("Solution", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205", nullptr));
        label_2->setText(QApplication::translate("Solution", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Solution: public Ui_Solution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTION_H
