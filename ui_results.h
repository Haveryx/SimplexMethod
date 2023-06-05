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
        Results->resize(1142, 654);
        Results->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(110,151,145);\n"
"}\n"
""));
        groupBox = new QGroupBox(Results);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(310, 10, 521, 611));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 521, 21));
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
