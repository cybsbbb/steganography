#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
     //Q_INIT_RESOURCE(steframe);
     QApplication app(argc, argv);
     MainWindow mainWindow;
     mainWindow.setWindowTitle("Steganography");
     mainWindow.setBaseSize(300,300);
     mainWindow.show();

     return app.exec();
}
