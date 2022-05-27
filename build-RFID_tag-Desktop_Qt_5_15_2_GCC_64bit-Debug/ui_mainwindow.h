/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *allremove;
    QTextEdit *rfiddata;
    QComboBox *comPortBox;
    QPushButton *update;
    QPushButton *connect;
    QLabel *label;
    QPushButton *disconnect;
    QFrame *frame;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(796, 501);
        MainWindow->setMinimumSize(QSize(796, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Logos/rfid.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(510, 280, 241, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(verticalLayoutWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout->addWidget(add);

        remove = new QPushButton(verticalLayoutWidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout->addWidget(remove);

        allremove = new QPushButton(verticalLayoutWidget);
        allremove->setObjectName(QString::fromUtf8("allremove"));
        allremove->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout->addWidget(allremove);

        rfiddata = new QTextEdit(centralwidget);
        rfiddata->setObjectName(QString::fromUtf8("rfiddata"));
        rfiddata->setGeometry(QRect(10, 320, 481, 71));
        rfiddata->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        comPortBox = new QComboBox(centralwidget);
        comPortBox->setObjectName(QString::fromUtf8("comPortBox"));
        comPortBox->setGeometry(QRect(0, 20, 191, 31));
        comPortBox->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(186, 189, 182);"));
        update = new QPushButton(centralwidget);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(10, 60, 71, 31));
        update->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        connect = new QPushButton(centralwidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(200, 20, 211, 31));
        connect->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 100, 171, 21));
        disconnect = new QPushButton(centralwidget);
        disconnect->setObjectName(QString::fromUtf8("disconnect"));
        disconnect->setGeometry(QRect(200, 50, 211, 31));
        disconnect->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(590, 20, 121, 51));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/new/p1/Logos/logo_mobil-1.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RFID Tag Manager Ye\305\237il Otomasyon 2020", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "Add RDIF Tag", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "Remove RFID Tag", nullptr));
        allremove->setText(QCoreApplication::translate("MainWindow", "Remove All Tags", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
