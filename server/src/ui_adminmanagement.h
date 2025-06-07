/********************************************************************************
** Form generated from reading UI file 'adminmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMANAGEMENT_H
#define UI_ADMINMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminManagement
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *UserManageTab;
    QGridLayout *gridLayout;
    QTableView *UserTable;
    QHBoxLayout *horizontalLayout;
    QLineEdit *UserInput;
    QPushButton *FindUserButton;
    QPushButton *DeleteUserButton;
    QPushButton *NewUserButton;
    QWidget *ChatManageTab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ChatInput;
    QPushButton *FindChatButton;
    QPushButton *DeleteChatButton;
    QPushButton *NewChatButton;
    QPushButton *ManageUserButton;
    QPushButton *ManageChatButton;
    QTableView *ChatTable;

    void setupUi(QWidget *AdminManagement)
    {
        if (AdminManagement->objectName().isEmpty())
            AdminManagement->setObjectName(QString::fromUtf8("AdminManagement"));
        AdminManagement->resize(973, 557);
        AdminManagement->setMinimumSize(QSize(960, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/manage.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AdminManagement->setWindowIcon(icon);
        AdminManagement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#030408;\n"
"color:#db9a45;\n"
"font-size: 10px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:30px;\n"
"width: 100%;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
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
        verticalLayout = new QVBoxLayout(AdminManagement);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(AdminManagement);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        UserManageTab = new QWidget();
        UserManageTab->setObjectName(QString::fromUtf8("UserManageTab"));
        gridLayout = new QGridLayout(UserManageTab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        UserTable = new QTableView(UserManageTab);
        UserTable->setObjectName(QString::fromUtf8("UserTable"));

        gridLayout->addWidget(UserTable, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        UserInput = new QLineEdit(UserManageTab);
        UserInput->setObjectName(QString::fromUtf8("UserInput"));
        UserInput->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(UserInput);

        FindUserButton = new QPushButton(UserManageTab);
        FindUserButton->setObjectName(QString::fromUtf8("FindUserButton"));

        horizontalLayout->addWidget(FindUserButton);

        DeleteUserButton = new QPushButton(UserManageTab);
        DeleteUserButton->setObjectName(QString::fromUtf8("DeleteUserButton"));

        horizontalLayout->addWidget(DeleteUserButton);

        NewUserButton = new QPushButton(UserManageTab);
        NewUserButton->setObjectName(QString::fromUtf8("NewUserButton"));

        horizontalLayout->addWidget(NewUserButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(UserManageTab, QString());
        ChatManageTab = new QWidget();
        ChatManageTab->setObjectName(QString::fromUtf8("ChatManageTab"));
        gridLayout_2 = new QGridLayout(ChatManageTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ChatInput = new QLineEdit(ChatManageTab);
        ChatInput->setObjectName(QString::fromUtf8("ChatInput"));
        ChatInput->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(ChatInput);

        FindChatButton = new QPushButton(ChatManageTab);
        FindChatButton->setObjectName(QString::fromUtf8("FindChatButton"));

        horizontalLayout_3->addWidget(FindChatButton);

        DeleteChatButton = new QPushButton(ChatManageTab);
        DeleteChatButton->setObjectName(QString::fromUtf8("DeleteChatButton"));

        horizontalLayout_3->addWidget(DeleteChatButton);

        NewChatButton = new QPushButton(ChatManageTab);
        NewChatButton->setObjectName(QString::fromUtf8("NewChatButton"));

        horizontalLayout_3->addWidget(NewChatButton);

        ManageUserButton = new QPushButton(ChatManageTab);
        ManageUserButton->setObjectName(QString::fromUtf8("ManageUserButton"));

        horizontalLayout_3->addWidget(ManageUserButton);

        ManageChatButton = new QPushButton(ChatManageTab);
        ManageChatButton->setObjectName(QString::fromUtf8("ManageChatButton"));

        horizontalLayout_3->addWidget(ManageChatButton);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        ChatTable = new QTableView(ChatManageTab);
        ChatTable->setObjectName(QString::fromUtf8("ChatTable"));

        gridLayout_2->addWidget(ChatTable, 3, 0, 1, 1);

        tabWidget->addTab(ChatManageTab, QString());

        verticalLayout->addWidget(tabWidget);

        QWidget::setTabOrder(UserInput, FindUserButton);
        QWidget::setTabOrder(FindUserButton, DeleteUserButton);
        QWidget::setTabOrder(DeleteUserButton, NewUserButton);
        QWidget::setTabOrder(NewUserButton, UserTable);
        QWidget::setTabOrder(UserTable, ChatInput);
        QWidget::setTabOrder(ChatInput, FindChatButton);
        QWidget::setTabOrder(FindChatButton, DeleteChatButton);
        QWidget::setTabOrder(DeleteChatButton, NewChatButton);
        QWidget::setTabOrder(NewChatButton, ManageUserButton);
        QWidget::setTabOrder(ManageUserButton, ManageChatButton);
        QWidget::setTabOrder(ManageChatButton, ChatTable);

        retranslateUi(AdminManagement);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminManagement);
    } // setupUi

    void retranslateUi(QWidget *AdminManagement)
    {
        AdminManagement->setWindowTitle(QCoreApplication::translate("AdminManagement", "\347\256\241\347\220\206\347\225\214\351\235\242", nullptr));
        FindUserButton->setText(QCoreApplication::translate("AdminManagement", "\346\237\245\350\257\242", nullptr));
        DeleteUserButton->setText(QCoreApplication::translate("AdminManagement", "\346\263\250\351\224\200\351\200\211\344\270\255\347\224\250\346\210\267", nullptr));
        NewUserButton->setText(QCoreApplication::translate("AdminManagement", "\346\226\260\345\242\236\347\224\250\346\210\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(UserManageTab), QCoreApplication::translate("AdminManagement", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        FindChatButton->setText(QCoreApplication::translate("AdminManagement", "\346\237\245\350\257\242", nullptr));
        DeleteChatButton->setText(QCoreApplication::translate("AdminManagement", "\350\247\243\346\225\243\351\200\211\344\270\255\347\276\244\350\201\212", nullptr));
        NewChatButton->setText(QCoreApplication::translate("AdminManagement", "\346\226\260\345\242\236\347\276\244\350\201\212", nullptr));
        ManageUserButton->setText(QCoreApplication::translate("AdminManagement", "\347\276\244\350\201\212\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        ManageChatButton->setText(QCoreApplication::translate("AdminManagement", "\347\276\244\350\201\212\346\266\210\346\201\257\347\256\241\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ChatManageTab), QCoreApplication::translate("AdminManagement", "\350\201\212\345\244\251\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminManagement: public Ui_AdminManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMANAGEMENT_H
