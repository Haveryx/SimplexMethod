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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rating
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_18;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_17;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_3;

    void setupUi(QWidget *Rating)
    {
        if (Rating->objectName().isEmpty())
            Rating->setObjectName(QStringLiteral("Rating"));
        Rating->resize(1194, 685);
        Rating->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 14pt \"Times New Roman\";\n"
"}\n"
"QGroupBox{\n"
"border-radius:10px;\n"
"border: 2px solid rgb(110,151,145);\n"
"}\n"
"QLabel{\n"
"font: 75 18pt \"Times New Roman\";\n"
"background-color: rgb(212, 188, 181);\n"
"}"));
        groupBox = new QGroupBox(Rating);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 10, 521, 651));
        groupBox->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 471, 31));
        label->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 40, 471, 21));
        label_18->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 79, 501, 561));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(311, 51));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(311, 51));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(311, 51));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(311, 51));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_17);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(311, 51));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(311, 51));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_12);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(311, 51));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_14);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(311, 51));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(141, 51));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(141, 51));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(141, 51));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        label_16 = new QLabel(widget1);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(141, 51));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_16);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(141, 51));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(widget1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(141, 51));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_13);

        label_15 = new QLabel(widget1);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(141, 51));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_15);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(141, 51));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        splitter->addWidget(widget1);

        retranslateUi(Rating);

        QMetaObject::connectSlotsByName(Rating);
    } // setupUi

    void retranslateUi(QWidget *Rating)
    {
        Rating->setWindowTitle(QApplication::translate("Rating", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Rating", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_18->setText(QApplication::translate("Rating", "\320\236\321\210\320\270\320\261\320\276\320\272:", nullptr));
        label_4->setText(QApplication::translate("Rating", "\320\237\321\200\320\270\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\272 \320\272\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\274\321\203\n"
" \320\262\320\270\320\264\321\203:", nullptr));
        label_6->setText(QApplication::translate("Rating", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \316\270:", nullptr));
        label_8->setText(QApplication::translate("Rating", "\320\222\321\213\320\261\320\276\321\200\320\260 \320\261\320\260\320\267\320\270\321\201\320\260/min \316\270:", nullptr));
        label_17->setText(QApplication::translate("Rating", "\320\237\321\200\320\270\320\262\320\270\320\264\320\265\320\275\320\270\321\217 \320\261\320\260\320\267\320\270\321\201\320\275\320\276\320\271\n"
"\320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\271:", nullptr));
        label_10->setText(QApplication::translate("Rating", "\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \321\201\321\202\320\276\320\261\321\206\320\260 C\320\261:", nullptr));
        label_12->setText(QApplication::translate("Rating", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \342\210\206k:", nullptr));
        label_14->setText(QApplication::translate("Rating", "\320\236\321\206\320\265\320\275\320\272\320\270 \342\210\206k:", nullptr));
        label_2->setText(QApplication::translate("Rating", "\320\230\321\202\320\276\320\263\320\276:", nullptr));
        label_5->setText(QString());
        label_7->setText(QString());
        label_9->setText(QString());
        label_16->setText(QString());
        label_11->setText(QString());
        label_13->setText(QString());
        label_15->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rating: public Ui_Rating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATING_H
