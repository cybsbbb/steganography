#include "login.h"
#include "ui_login.h"
#include <qmessagebox.h>
#include <QtGui>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->password_edit->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_login_button_clicked()
{
    if(ui->username_edit->text().trimmed() == tr("cybsb") && ui->password_edit->text() == tr("limaizhlj1"))
        accept();
    else{
		QMessageBox::warning(this,tr("我的天呐"),tr("name \n or \n password \n error!"),QMessageBox::Yes);
    }
    ui->username_edit->clear();
    ui->password_edit->clear();
    ui->username_edit->setFocus();
}

