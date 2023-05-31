/********************************************************************************
** Form generated from reading UI file 'training.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINING_H
#define UI_TRAINING_H

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

class Ui_Training
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Training)
    {
        if (Training->objectName().isEmpty())
            Training->setObjectName(QStringLiteral("Training"));
        Training->resize(932, 512);
        Training->setStyleSheet(QLatin1String("/*Training{\n"
"background-color: rgb(212, 188, 181);\n"
"}\n"
"*/\n"
"QPushButton{\n"
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
"}\n"
"QRadioButton{\n"
"font: 75 18pt \"Times New Roman\";\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(110,151,145);\n"
"\n"
"}\n"
"QComboBox{\n"
"background-color: rgb(117, 174, 143);\n"
"}\n"
"QLabel#label_3{\n"
"font: 75 18pt \"Times New Roman\";\n"
"background-color: rgb(214,153,146);\n"
"}\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"background-color: rgb(212, 188, 181);\n"
"}"));
        lineEdit = new QLineEdit(Training);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(390, 50, 151, 51));
        label = new QLabel(Training);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 291, 51));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Training);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 160, 281, 51));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Training);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 270, 241, 61));
        groupBox = new QGroupBox(Training);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(580, 50, 141, 161));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        lineEdit_2 = new QLineEdit(Training);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(390, 160, 151, 51));
        label_3 = new QLabel(Training);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(160, 10, 401, 21));
        pushButton_2 = new QPushButton(Training);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 0, 75, 23));

        retranslateUi(Training);

        QMetaObject::connectSlotsByName(Training);
    } // setupUi

    void retranslateUi(QWidget *Training)
    {
        Training->setWindowTitle(QApplication::translate("Training", "Form", nullptr));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("Training", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205", nullptr));
        label_2->setText(QApplication::translate("Training", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271", nullptr));
        pushButton->setText(QApplication::translate("Training", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("Training", "Min", nullptr));
        radioButton_2->setText(QApplication::translate("Training", "Max", nullptr));
        lineEdit_2->setText(QString());
        label_3->setText(QApplication::translate("Training", "\320\235\320\265 \320\277\321\200\320\270\320\262\320\265\320\264\320\265\320\275\320\276 \320\272 \320\272\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\274\321\203 \320\262\320\270\320\264\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("Training", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Training: public Ui_Training {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINING_H
