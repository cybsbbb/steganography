#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
     //Q_INIT_RESOURCE(steframe);
     QApplication app(argc, argv);
     MainWindow mainWindow;
     mainWindow.setWindowTitle("Steganography");
     mainWindow.setBaseSize(300,300);

     login login;
     if(login.exec() == QDialog::Accepted){
         mainWindow.show();
         return app.exec();

     }

}
