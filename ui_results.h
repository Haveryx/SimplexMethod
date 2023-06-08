/********************************************************************************
** Form generated from reading UI file 'results.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTS_H
#define UI_RESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Results
{
public:
    QGroupBox *groupBox;
    QLabel *label;

    void setupUi(QWidget *Results)
    {
        if (Results->objectName().isEmpty())
            Results->setObjectName(QStringLiteral("Results"));
        Results->resize(1205, 713);
        Results->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 4px solid rgb(163, 137, 131);\n"
"background-color: rgb(255, 240, 245);\n"
"}\n"
"QLabel#label{\n"
"font: 75 20pt \"Times New Roman\";\n"
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
"}"));
        groupBox = new QGroupBox(Results);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(250, 0, 691, 661));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 180, 681, 21));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Results);

        QMetaObject::connectSlotsByName(Results);
    } // setupUi

    void retranslateUi(QWidget *Results)
    {
        Results->setWindowTitle(QApplication::translate("Results", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Results", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Results: public Ui_Results {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTS_H
