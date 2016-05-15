/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *login_button;
    QPushButton *close_button;
    QLineEdit *username_edit;
    QLineEdit *password_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *login_title;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(376, 286);
        login_button = new QPushButton(login);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(97, 220, 75, 23));
        close_button = new QPushButton(login);
        close_button->setObjectName(QStringLiteral("close_button"));
        close_button->setGeometry(QRect(207, 220, 75, 23));
        username_edit = new QLineEdit(login);
        username_edit->setObjectName(QStringLiteral("username_edit"));
        username_edit->setGeometry(QRect(177, 100, 113, 20));
        password_edit = new QLineEdit(login);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(177, 160, 113, 20));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 100, 71, 21));
        label->setLineWidth(4);
        label->setTextFormat(Qt::AutoText);
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 160, 71, 21));
        login_title = new QLabel(login);
        login_title->setObjectName(QStringLiteral("login_title"));
        login_title->setGeometry(QRect(130, 40, 120, 27));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setItalic(false);
        login_title->setFont(font);

        retranslateUi(login);
        QObject::connect(close_button, SIGNAL(clicked()), login, SLOT(close()));

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0));
        login_button->setText(QApplication::translate("login", "login", 0));
        close_button->setText(QApplication::translate("login", "close", 0));
        label->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" font-size:12pt;\">Username</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" font-size:12pt;\">password</span></p></body></html>", 0));
        login_title->setText(QApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\345\234\250\350\277\231\351\207\214\347\231\273\345\275\225</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
