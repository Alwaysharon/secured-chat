/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *PortInput;
    QLineEdit *IPInput;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *AdminInput;
    QSpacerItem *horizontalSpacer;
    QLineEdit *PassWordInput;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CloseButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        Widget->setMinimumSize(QSize(400, 300));
        Widget->setMaximumSize(QSize(400, 300));
        Widget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#030408;\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:44px;\n"
"width: 100%;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}\n"
"QFrame{\n"
"margin:2px;\n"
"border: 1px solid #dcdee0;;\n"
"border-radius: 24px;\n"
"background-color:rgb(255, 255, 255);\n"
"padding:10px;\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid rgb(41, 57, 85);\n"
"border-radius: 3px;\n"
"border-color:#dcdee0;\n"
"height:36px;\n"
"background: white;\n"
"padding-left: 12px;\n"
"padding-right: 12px;\n"
"border-color:#e4e5eb;\n"
"}\n"
"QLineEdit:hover {\n"
"border-color: #db9a45;\n"
"}"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PortInput = new QLineEdit(frame);
        PortInput->setObjectName(QString::fromUtf8("PortInput"));

        gridLayout->addWidget(PortInput, 1, 1, 1, 1);

        IPInput = new QLineEdit(frame);
        IPInput->setObjectName(QString::fromUtf8("IPInput"));

        gridLayout->addWidget(IPInput, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        AdminInput = new QLineEdit(frame);
        AdminInput->setObjectName(QString::fromUtf8("AdminInput"));

        gridLayout->addWidget(AdminInput, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        PassWordInput = new QLineEdit(frame);
        PassWordInput->setObjectName(QString::fromUtf8("PassWordInput"));
        PassWordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(PassWordInput, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        LoginButton = new QPushButton(frame);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));

        horizontalLayout->addWidget(LoginButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));

        horizontalLayout->addWidget(CloseButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(frame);

        QWidget::setTabOrder(IPInput, PortInput);
        QWidget::setTabOrder(PortInput, AdminInput);
        QWidget::setTabOrder(AdminInput, PassWordInput);
        QWidget::setTabOrder(PassWordInput, LoginButton);
        QWidget::setTabOrder(LoginButton, CloseButton);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257\347\231\273\345\275\225", nullptr));
        PortInput->setText(QCoreApplication::translate("Widget", "12345", nullptr));
        PortInput->setPlaceholderText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243", nullptr));
        IPInput->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        IPInput->setPlaceholderText(QCoreApplication::translate("Widget", "IP\345\234\260\345\235\200", nullptr));
        AdminInput->setPlaceholderText(QCoreApplication::translate("Widget", "\350\266\205\347\272\247\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267", nullptr));
        PassWordInput->setPlaceholderText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        LoginButton->setText(QCoreApplication::translate("Widget", "\345\273\272\347\253\213", nullptr));
        CloseButton->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
