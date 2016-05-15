#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>  
#include <fstream>  

#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QWidget>
#include <QImage>
#include <QPainter>
#include <qfiledialog.h>
#include <QCloseEvent>
#include <QPushButton>

#include <algorithm.h>

using namespace std;

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QToolBar;
class QFileDialog;
class QMessageBox;
class QButton;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotabout();
    void slotopenFile();
    bool slotsaveFile();
    bool slotsaveAs();
    void slotclose();

    void on_steButton_clicked();
    void on_showButton_clicked();

private:
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *steMenu;

    QAction *openAct;
    QAction *exitAct;
    QAction *saveAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *steAct;

    QToolBar *toolbar_;

    //QPushButton *steButton;

    QString curFile;

    void createActions();
    void createMenus();
    void createToolbars();
    void createButtons();
    bool savePic(const QString &fileName);

protected:
    void paint(const QString &filename);
    void closeEvent();

public:
    QImage img;
	QImage img_after_ste;
    Algorithm *ste_Algo;

private:
    Ui::MainWindow *ui;
    //QMdiSubWindow *centralWidget;
    QGraphicsView *view;
};

#endif // MAINWINDOW_H
