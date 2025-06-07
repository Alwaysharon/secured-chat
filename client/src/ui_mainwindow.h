/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *PortInput;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *IPInput;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ConnectButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setMaximumSize(QSize(400, 300));
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"background: white;\n"
"padding-left: 12px;\n"
"padding-right: 12px;\n"
"border-color:#e4e5eb;\n"
"}\n"
"QLineEdit:hover {\n"
"border-color: #db9a45;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PortInput = new QLineEdit(frame);
        PortInput->setObjectName(QString::fromUtf8("PortInput"));
        PortInput->setMinimumSize(QSize(0, 45));

        gridLayout->addWidget(PortInput, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        IPInput = new QLineEdit(frame);
        IPInput->setObjectName(QString::fromUtf8("IPInput"));
        IPInput->setMinimumSize(QSize(0, 45));

        gridLayout->addWidget(IPInput, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ConnectButton = new QPushButton(frame);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

        horizontalLayout->addWidget(ConnectButton);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(CloseButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(IPInput, PortInput);
        QWidget::setTabOrder(PortInput, ConnectButton);
        QWidget::setTabOrder(ConnectButton, CloseButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        PortInput->setText(QString());
        PortInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        IPInput->setText(QString());
        IPInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "IP\345\234\260\345\235\200", nullptr));
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        CloseButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
