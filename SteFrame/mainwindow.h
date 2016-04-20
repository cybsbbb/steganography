#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QWidget>
#include <QImage>
#include <QPainter>

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
    void slotclose();
    void slotopenFile();
    void slotsaveFile();

private:
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *exitAct;
    QAction *saveAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QToolBar *toolbar_;

    void createActions();
    void createMenus();
    void createToolbars();

protected:
    void paint(const QString &filename);

public:
    QImage img;

private:
    Ui::MainWindow *ui;
    QMdiSubWindow *centralWidget;

};

#endif // MAINWINDOW_H
