/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *NameInput;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *PassWordInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *CloseButton;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 297);
        LoginWindow->setMinimumSize(QSize(400, 0));
        LoginWindow->setMaximumSize(QSize(400, 300));
        LoginWindow->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border: 1px solid #dcdee0;;\n"
"border-radius: 12px;\n"
"background-color:rgb(255, 255, 255);\n"
"}\n"
"QLineEdit{\n"
"border: 1px solid rgb(41, 57, 85);\n"
"border-radius: 3px;\n"
"border-color:#dcdee0;\n"
"background: white;\n"
"padding-left: 12px;\n"
"padding-right: 12px;\n"
"border-color:#e4e5eb;\n"
"}\n"
"QLineEdit:hover {\n"
"border-color: #db9a45;\n"
"}"));
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(LoginWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        NameInput = new QLineEdit(frame);
        NameInput->setObjectName(QString::fromUtf8("NameInput"));
        NameInput->setMinimumSize(QSize(0, 45));

        gridLayout->addWidget(NameInput, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        PassWordInput = new QLineEdit(frame);
        PassWordInput->setObjectName(QString::fromUtf8("PassWordInput"));
        PassWordInput->setMinimumSize(QSize(0, 45));
        PassWordInput->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(PassWordInput, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LoginButton = new QPushButton(frame);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:44px;\n"
"width: 100%;\n"
"background-color:#030408;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}"));

        horizontalLayout->addWidget(LoginButton);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        RegisterButton = new QPushButton(frame);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        RegisterButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:44px;\n"
"width: 100%;\n"
"background-color:#030408;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}"));

        horizontalLayout->addWidget(RegisterButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:44px;\n"
"width: 100%;\n"
"background-color:#030408;\n"
"}"));

        horizontalLayout->addWidget(CloseButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        NameInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        PassWordInput->setText(QString());
        PassWordInput->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        RegisterButton->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
        CloseButton->setText(QCoreApplication::translate("LoginWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
