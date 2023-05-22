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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Solution)
    {
        if (Solution->objectName().isEmpty())
            Solution->setObjectName(QStringLiteral("Solution"));
        Solution->resize(539, 423);
        groupBox = new QGroupBox(Solution);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(400, 20, 108, 85));
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
        pushButton->setGeometry(QRect(220, 130, 80, 21));
        layoutWidget = new QWidget(Solution);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 50, 110, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        layoutWidget1 = new QWidget(Solution);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 50, 147, 53));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);


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
