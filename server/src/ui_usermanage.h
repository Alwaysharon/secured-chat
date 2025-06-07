/********************************************************************************
** Form generated from reading UI file 'usermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManage
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ContentInput;
    QPushButton *FindButton;
    QPushButton *DeleteButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ChatName;
    QSpacerItem *horizontalSpacer;
    QLabel *ChatID;
    QSpacerItem *horizontalSpacer_2;
    QTableView *UserTable;

    void setupUi(QWidget *UserManage)
    {
        if (UserManage->objectName().isEmpty())
            UserManage->setObjectName(QString::fromUtf8("UserManage"));
        UserManage->resize(783, 548);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/manage.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/manage.png"), QSize(), QIcon::Disabled, QIcon::On);
        UserManage->setWindowIcon(icon);
        UserManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#030408;\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
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
        gridLayout = new QGridLayout(UserManage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ContentInput = new QLineEdit(UserManage);
        ContentInput->setObjectName(QString::fromUtf8("ContentInput"));
        ContentInput->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(ContentInput);

        FindButton = new QPushButton(UserManage);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));

        horizontalLayout->addWidget(FindButton);

        DeleteButton = new QPushButton(UserManage);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ChatName = new QLabel(UserManage);
        ChatName->setObjectName(QString::fromUtf8("ChatName"));

        horizontalLayout_2->addWidget(ChatName);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ChatID = new QLabel(UserManage);
        ChatID->setObjectName(QString::fromUtf8("ChatID"));

        horizontalLayout_2->addWidget(ChatID);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        UserTable = new QTableView(UserManage);
        UserTable->setObjectName(QString::fromUtf8("UserTable"));

        gridLayout->addWidget(UserTable, 2, 0, 1, 1);

        QWidget::setTabOrder(ContentInput, FindButton);
        QWidget::setTabOrder(FindButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, UserTable);

        retranslateUi(UserManage);

        QMetaObject::connectSlotsByName(UserManage);
    } // setupUi

    void retranslateUi(QWidget *UserManage)
    {
        UserManage->setWindowTitle(QCoreApplication::translate("UserManage", "\347\276\244\350\201\212\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        FindButton->setText(QCoreApplication::translate("UserManage", "\346\237\245\350\257\242", nullptr));
        DeleteButton->setText(QCoreApplication::translate("UserManage", "\347\247\273\345\207\272\351\200\211\344\270\255\347\224\250\346\210\267", nullptr));
        ChatName->setText(QCoreApplication::translate("UserManage", "TextLabel", nullptr));
        ChatID->setText(QCoreApplication::translate("UserManage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManage: public Ui_UserManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
