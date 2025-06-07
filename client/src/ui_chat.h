/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *chatNamelabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *chatBrowser;
    QSpacerItem *verticalSpacer;
    QTextEdit *MessageInput;
    QPushButton *SendButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *Imagelabel;
    QVBoxLayout *verticalLayout;
    QLabel *userlistLabel;
    QListWidget *UserlistWidget;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(861, 548);
        Chat->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Chat);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(Chat);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"background-color: rgba(255, 255, 255,0.9);\n"
"border-radius: 16px;\n"
"}\n"
"QLabel{\n"
"front-color:rgb(255, 255, 255);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chatNamelabel = new QLabel(frame);
        chatNamelabel->setObjectName(QString::fromUtf8("chatNamelabel"));
        chatNamelabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(chatNamelabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setMaximumSize(QSize(20, 20));
        CloseButton->setStyleSheet(QString::fromUtf8("#CloseButton{\n"
"border:none;\n"
"background:rgba(255,255,255,0.4);\n"
"}\n"
"#CloseButton:hover {\n"
"background: rgba(255,255,255,0.7);\n"
"}"));

        horizontalLayout->addWidget(CloseButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chatBrowser = new QTextBrowser(frame);
        chatBrowser->setObjectName(QString::fromUtf8("chatBrowser"));
        chatBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser{\n"
"background-color:#D4D4D3;\n"
"}"));

        verticalLayout_2->addWidget(chatBrowser);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        MessageInput = new QTextEdit(frame);
        MessageInput->setObjectName(QString::fromUtf8("MessageInput"));
        MessageInput->setMaximumSize(QSize(16777215, 200));
        MessageInput->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"background-color:#D4D4D3;\n"
"}"));

        verticalLayout_2->addWidget(MessageInput);

        SendButton = new QPushButton(frame);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#030408;\n"
"color:#db9a45;\n"
"font-size: 20px;\n"
"font:10pt \"Microsoft YaHei UI\";\n"
"border-radius:8px;\n"
"font-weight:700;\n"
"height:35px;\n"
"width: 100%;\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #787a7e;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #383a3e;\n"
"}"));

        verticalLayout_2->addWidget(SendButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        Imagelabel = new QLabel(frame);
        Imagelabel->setObjectName(QString::fromUtf8("Imagelabel"));
        Imagelabel->setMinimumSize(QSize(200, 200));
        Imagelabel->setMaximumSize(QSize(200, 200));
        Imagelabel->setPixmap(QPixmap(QString::fromUtf8(":/pic/0.jpg")));

        verticalLayout_3->addWidget(Imagelabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userlistLabel = new QLabel(frame);
        userlistLabel->setObjectName(QString::fromUtf8("userlistLabel"));

        verticalLayout->addWidget(userlistLabel);

        UserlistWidget = new QListWidget(frame);
        UserlistWidget->setObjectName(QString::fromUtf8("UserlistWidget"));
        UserlistWidget->setMaximumSize(QSize(200, 16777215));
        UserlistWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(UserlistWidget);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        QWidget::setTabOrder(chatBrowser, MessageInput);
        QWidget::setTabOrder(MessageInput, SendButton);
        QWidget::setTabOrder(SendButton, UserlistWidget);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QCoreApplication::translate("Chat", "Form", nullptr));
        chatNamelabel->setText(QCoreApplication::translate("Chat", "TextLabel", nullptr));
        CloseButton->setText(QString());
        MessageInput->setHtml(QCoreApplication::translate("Chat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        SendButton->setText(QCoreApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        Imagelabel->setText(QString());
        userlistLabel->setText(QCoreApplication::translate("Chat", "\350\201\212\345\244\251\345\256\244\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
