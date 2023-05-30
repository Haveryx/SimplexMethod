/********************************************************************************
** Form generated from reading UI file 'rating.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATING_H
#define UI_RATING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rating
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Rating)
    {
        if (Rating->objectName().isEmpty())
            Rating->setObjectName(QStringLiteral("Rating"));
        Rating->resize(1194, 685);
        Rating->setStyleSheet(QLatin1String("QLabel{\n"
"background-color: rgb(212, 188, 181);\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(110,151,145);\n"
"\n"
"}"));
        groupBox = new QGroupBox(Rating);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 10, 471, 651));
        groupBox->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 471, 31));
        label->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 480, 471, 31));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 540, 471, 31));
        label_15->setAlignment(Qt::AlignCenter);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(2, 400, 471, 41));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_2->addWidget(label_12);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(2, 260, 471, 41));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        widget2 = new QWidget(groupBox);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(2, 120, 471, 41));
        horizontalLayout_6 = new QHBoxLayout(widget2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        widget3 = new QWidget(groupBox);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(1, 46, 471, 41));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        widget4 = new QWidget(groupBox);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(2, 330, 471, 41));
        horizontalLayout_3 = new QHBoxLayout(widget4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(widget4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        widget5 = new QWidget(groupBox);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(2, 190, 471, 41));
        horizontalLayout_5 = new QHBoxLayout(widget5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        label_7 = new QLabel(widget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);


        retranslateUi(Rating);

        QMetaObject::connectSlotsByName(Rating);
    } // setupUi

    void retranslateUi(QWidget *Rating)
    {
        Rating->setWindowTitle(QApplication::translate("Rating", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Rating", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_14->setText(QApplication::translate("Rating", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        label_15->setText(QString());
        label_12->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272 \320\277\321\200\320\270 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\270 \320\264\320\265\320\273\321\214\321\202\321\213:", nullptr));
        label_13->setText(QString());
        label_8->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 \320\261\320\260\320\267\320\270\321\201\320\260/ \321\202\320\265\321\202:", nullptr));
        label_9->setText(QString());
        label_4->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272 \320\262 \320\272\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\274 \320\262\320\270\320\264\320\265:", nullptr));
        label_5->setText(QString());
        label_2->setText(QApplication::translate("Rating", "\320\222\321\201\320\265\320\263\320\276 \320\276\321\210\320\270\320\261\320\276\320\272:", nullptr));
        label_3->setText(QString());
        label_10->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272 \320\277\321\200\320\270 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270 \321\201\321\202\320\276\320\261\321\206\320\260 C:", nullptr));
        label_11->setText(QString());
        label_6->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272 \320\277\321\200\320\270 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\270 \321\202\320\265\321\202\321\202:", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rating: public Ui_Rating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATING_H
