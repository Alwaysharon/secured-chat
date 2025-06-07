/********************************************************************************
** Form generated from reading UI file 'messagemanage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEMANAGE_H
#define UI_MESSAGEMANAGE_H

#include <QtCore/QVariant>
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

class Ui_MessageManage
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ContentInput;
    QPushButton *FindUserButton;
    QPushButton *FindContentButton;
    QPushButton *DeleteButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ChatName;
    QSpacerItem *horizontalSpacer;
    QLabel *ChatID;
    QSpacerItem *horizontalSpacer_2;
    QTableView *MessageTable;

    void setupUi(QWidget *MessageManage)
    {
        if (MessageManage->objectName().isEmpty())
            MessageManage->setObjectName(QString::fromUtf8("MessageManage"));
        MessageManage->resize(797, 480);
        MessageManage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        gridLayout = new QGridLayout(MessageManage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ContentInput = new QLineEdit(MessageManage);
        ContentInput->setObjectName(QString::fromUtf8("ContentInput"));
        ContentInput->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(ContentInput);

        FindUserButton = new QPushButton(MessageManage);
        FindUserButton->setObjectName(QString::fromUtf8("FindUserButton"));

        horizontalLayout->addWidget(FindUserButton);

        FindContentButton = new QPushButton(MessageManage);
        FindContentButton->setObjectName(QString::fromUtf8("FindContentButton"));

        horizontalLayout->addWidget(FindContentButton);

        DeleteButton = new QPushButton(MessageManage);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ChatName = new QLabel(MessageManage);
        ChatName->setObjectName(QString::fromUtf8("ChatName"));

        horizontalLayout_2->addWidget(ChatName);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ChatID = new QLabel(MessageManage);
        ChatID->setObjectName(QString::fromUtf8("ChatID"));

        horizontalLayout_2->addWidget(ChatID);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MessageTable = new QTableView(MessageManage);
        MessageTable->setObjectName(QString::fromUtf8("MessageTable"));

        gridLayout->addWidget(MessageTable, 2, 0, 1, 1);

        QWidget::setTabOrder(ContentInput, FindUserButton);
        QWidget::setTabOrder(FindUserButton, FindContentButton);
        QWidget::setTabOrder(FindContentButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, MessageTable);

        retranslateUi(MessageManage);

        QMetaObject::connectSlotsByName(MessageManage);
    } // setupUi

    void retranslateUi(QWidget *MessageManage)
    {
        MessageManage->setWindowTitle(QCoreApplication::translate("MessageManage", "\347\276\244\350\201\212\346\266\210\346\201\257\347\256\241\347\220\206\347\225\214\351\235\242", nullptr));
        FindUserButton->setText(QCoreApplication::translate("MessageManage", "\346\237\245\350\257\242\347\224\250\346\210\267\345\220\215", nullptr));
        FindContentButton->setText(QCoreApplication::translate("MessageManage", "\346\237\245\350\257\242\346\266\210\346\201\257\345\206\205\345\256\271", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MessageManage", "\346\222\244\345\233\236\351\200\211\344\270\255\346\266\210\346\201\257", nullptr));
        ChatName->setText(QCoreApplication::translate("MessageManage", "TextLabel", nullptr));
        ChatID->setText(QCoreApplication::translate("MessageManage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageManage: public Ui_MessageManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEMANAGE_H
