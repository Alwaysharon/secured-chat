/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatList
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *UserNameLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *closeButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *HJoinChat;
    QSpacerItem *horizontalSpacer;
    QPushButton *OpenChatButton;
    QVBoxLayout *verticalLayout_2;
    QListWidget *HJoinChatListWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ChatNameInput;
    QPushButton *FindChatButton;
    QPushButton *NewChatButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UJoinChat;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *JoinButton;
    QListWidget *UJoinChatListWidget;

    void setupUi(QWidget *ChatList)
    {
        if (ChatList->objectName().isEmpty())
            ChatList->setObjectName(QString::fromUtf8("ChatList"));
        ChatList->resize(500, 606);
        ChatList->setMaximumSize(QSize(500, 930));
        ChatList->setStyleSheet(QString::fromUtf8("#frame{\n"
"border: 1px solid rgb(41, 57, 85);\n"
"border-radius: 10px;\n"
"border-color:#dcdee0;\n"
"background-color: rgba(255, 255, 255,0.9);\n"
"}\n"
"QLabel{\n"
"color:rgb(0, 0, 0)\n"
"}\n"
"QPushButton {\n"
"background-color:#030408;\n"
"color:#db9a45;\n"
"font:9pt \"Microsoft YaHei UI\";\n"
"border-radius:5px;\n"
"font-weight:650;\n"
"height:25px;\n"
"width: 80%;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}\n"
"QListWidget{\n"
"background:rgba(255,255,255,0.7);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(ChatList);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(ChatList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(500, 930));
        frame->setStyleSheet(QString::fromUtf8("#frame{border-image:url(pic/listback3.jpg)}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        UserNameLabel = new QLabel(frame);
        UserNameLabel->setObjectName(QString::fromUtf8("UserNameLabel"));

        horizontalLayout_4->addWidget(UserNameLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        closeButton = new QPushButton(frame);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMaximumSize(QSize(20, 20));
        closeButton->setStyleSheet(QString::fromUtf8("#closeButton{\n"
"border:none;\n"
"background:rgba(255,255,255,0.4);\n"
"}\n"
"#closeButton:hover {\n"
"background: rgba(255,255,255,0.7);\n"
"}"));

        horizontalLayout_4->addWidget(closeButton);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        HJoinChat = new QLabel(frame);
        HJoinChat->setObjectName(QString::fromUtf8("HJoinChat"));

        horizontalLayout->addWidget(HJoinChat);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OpenChatButton = new QPushButton(frame);
        OpenChatButton->setObjectName(QString::fromUtf8("OpenChatButton"));

        horizontalLayout->addWidget(OpenChatButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        HJoinChatListWidget = new QListWidget(frame);
        HJoinChatListWidget->setObjectName(QString::fromUtf8("HJoinChatListWidget"));

        verticalLayout_2->addWidget(HJoinChatListWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ChatNameInput = new QLineEdit(frame);
        ChatNameInput->setObjectName(QString::fromUtf8("ChatNameInput"));
        ChatNameInput->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 1px solid rgb(41, 57, 85);\n"
"border-radius: 3px;\n"
"border-color:#dcdee0;\n"
"background: rgba(255,255,255,0.6);\n"
"padding-left: 12px;\n"
"padding-right: 12px;\n"
"border-color:#e4e5eb;\n"
"}\n"
"QLineEdit:hover {\n"
"border-color: #db9a45;\n"
"}"));

        horizontalLayout_3->addWidget(ChatNameInput);

        FindChatButton = new QPushButton(frame);
        FindChatButton->setObjectName(QString::fromUtf8("FindChatButton"));

        horizontalLayout_3->addWidget(FindChatButton);

        NewChatButton = new QPushButton(frame);
        NewChatButton->setObjectName(QString::fromUtf8("NewChatButton"));

        horizontalLayout_3->addWidget(NewChatButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        UJoinChat = new QLabel(frame);
        UJoinChat->setObjectName(QString::fromUtf8("UJoinChat"));

        horizontalLayout_2->addWidget(UJoinChat);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        JoinButton = new QPushButton(frame);
        JoinButton->setObjectName(QString::fromUtf8("JoinButton"));

        horizontalLayout_2->addWidget(JoinButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        UJoinChatListWidget = new QListWidget(frame);
        UJoinChatListWidget->setObjectName(QString::fromUtf8("UJoinChatListWidget"));

        verticalLayout_2->addWidget(UJoinChatListWidget);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);


        verticalLayout_3->addWidget(frame);


        retranslateUi(ChatList);

        QMetaObject::connectSlotsByName(ChatList);
    } // setupUi

    void retranslateUi(QWidget *ChatList)
    {
        ChatList->setWindowTitle(QCoreApplication::translate("ChatList", "\347\276\244\350\201\212\345\210\227\350\241\250", nullptr));
        UserNameLabel->setText(QCoreApplication::translate("ChatList", "TextLabel", nullptr));
        closeButton->setText(QString());
        HJoinChat->setText(QCoreApplication::translate("ChatList", "\345\267\262\345\212\240\345\205\245\347\232\204\347\276\244\350\201\212", nullptr));
        OpenChatButton->setText(QCoreApplication::translate("ChatList", "\346\211\223\345\274\200\347\276\244\350\201\212", nullptr));
        FindChatButton->setText(QCoreApplication::translate("ChatList", "\346\220\234\347\264\242", nullptr));
        NewChatButton->setText(QCoreApplication::translate("ChatList", "\345\210\233\345\273\272\346\226\260\347\276\244\350\201\212", nullptr));
        UJoinChat->setText(QCoreApplication::translate("ChatList", "\346\234\252\345\212\240\345\205\245\347\232\204\347\276\244\350\201\212", nullptr));
        JoinButton->setText(QCoreApplication::translate("ChatList", "\345\212\240\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatList: public Ui_ChatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
