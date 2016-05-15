/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *picLayout;
    QWidget *picWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGroupBox *ste_groupBox;
    QPushButton *steButton;
    QLineEdit *inputEdit;
    QGroupBox *show_groupBox;
    QPushButton *showButton;
    QTextBrowser *showBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(765, 480);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/support.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 511, 421));
        picLayout = new QVBoxLayout(verticalLayoutWidget);
        picLayout->setSpacing(6);
        picLayout->setContentsMargins(11, 11, 11, 11);
        picLayout->setObjectName(QStringLiteral("picLayout"));
        picLayout->setContentsMargins(0, 0, 0, 0);
        picWidget = new QWidget(verticalLayoutWidget);
        picWidget->setObjectName(QStringLiteral("picWidget"));

        picLayout->addWidget(picWidget);

        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(570, 20, 181, 421));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("font: 18pt \"Blackadder ITC\";"));
        ste_groupBox = new QGroupBox(groupBox);
        ste_groupBox->setObjectName(QStringLiteral("ste_groupBox"));
        ste_groupBox->setGeometry(QRect(0, 50, 181, 171));
        ste_groupBox->setStyleSheet(QStringLiteral("font: 16pt \"Bradley Hand ITC\";"));
        steButton = new QPushButton(ste_groupBox);
        steButton->setObjectName(QStringLiteral("steButton"));
        steButton->setGeometry(QRect(50, 120, 75, 23));
        steButton->setMaximumSize(QSize(75, 23));
        steButton->setStyleSheet(QStringLiteral("font: 9pt \"Bodoni MT\";"));
        inputEdit = new QLineEdit(ste_groupBox);
        inputEdit->setObjectName(QStringLiteral("inputEdit"));
        inputEdit->setGeometry(QRect(20, 60, 131, 20));
        inputEdit->setStyleSheet(QStringLiteral("font: 9pt \"Gadugi\";"));
        show_groupBox = new QGroupBox(groupBox);
        show_groupBox->setObjectName(QStringLiteral("show_groupBox"));
        show_groupBox->setGeometry(QRect(0, 220, 181, 191));
        show_groupBox->setStyleSheet(QStringLiteral("font: 15pt \"Bradley Hand ITC\";"));
        showButton = new QPushButton(show_groupBox);
        showButton->setObjectName(QStringLiteral("showButton"));
        showButton->setGeometry(QRect(50, 140, 81, 23));
        showButton->setStyleSheet(QStringLiteral("font: 9pt \"Berlin Sans FB\";"));
        showBrowser = new QTextBrowser(show_groupBox);
        showBrowser->setObjectName(QStringLiteral("showBrowser"));
        showBrowser->setGeometry(QRect(20, 40, 131, 81));

        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(widget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Algorithm", 0));
        ste_groupBox->setTitle(QApplication::translate("MainWindow", "Stegano", 0));
        steButton->setText(QApplication::translate("MainWindow", "Do Stegano", 0));
        inputEdit->setText(QString());
        show_groupBox->setTitle(QApplication::translate("MainWindow", "Show Message", 0));
        showButton->setText(QApplication::translate("MainWindow", "Show", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
