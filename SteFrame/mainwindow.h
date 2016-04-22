#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QWidget>
#include <QImage>
#include <QPainter>
#include <iostream.h>
#include <qfiledialog.h>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QToolBar;
class QFileDialog;
class QMessageBox;
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

private:
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *exitAct;
    QAction *saveAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QToolBar *toolbar_;

    QString curFile;

    void createActions();
    void createMenus();
    void createToolbars();
    bool savePic(const QString &fileName);

protected:
    void paint(const QString &filename);

public:
    QImage img;

private:
    Ui::MainWindow *ui;
    QMdiSubWindow *centralWidget;

};

#endif // MAINWINDOW_H
