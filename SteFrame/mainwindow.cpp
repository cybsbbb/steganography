#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QTabWidget>
#include <QBrush>
#include <QMdiArea>
#include <QtWidgets>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolbars();
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint(const QString &filename)
{
    centralWidget = new QMdiSubWindow(ui->widget);

    QPixmap pixmap=QPixmap::fromImage(img);

    QGraphicsView *view = new QGraphicsView(centralWidget->widget());
    QGraphicsScene *scene = new QGraphicsScene;

    scene->addPixmap(pixmap);
    view->setWindowTitle(filename);
    view->setScene(scene);
    view->resize(img.width() + 10, img.height() + 10);
    view->show();

 }

void MainWindow::createActions()
{
    openAct = new QAction(QIcon(":/Images/fileopen.png"),tr("O&pen"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open the Image"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(slotopenFile()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setStatusTip(tr("Exit the application"));
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    saveAct = new QAction(QIcon(":/Images/save.png"),tr("S&ave"), this);
    saveAct->setStatusTip(tr("Save the Image"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(slotsaveFile()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(slotabout()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(slotaboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(exitAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolbars()
{
    toolbar_ = this->addToolBar(tr("Main ToolBar"));
    toolbar_->addAction(openAct);
    toolbar_->addAction(saveAct);

    statusBar();
}

bool MainWindow::savePic(const QString &fileName)
{
    if(!(img.save(fileName)))
    {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot save Picture."));
        return false;
    }
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::slotabout()
{
    QMessageBox::about(this, tr("About Steganography"),tr("The <b>Steganography</b>  "
                                                          "is a program using Steganography to encrypt pictures"));

}

void MainWindow::slotopenFile()
{
    //if there is an image have already been opened,RETURN.
    if (!(curFile.isEmpty()))
    {
        QMessageBox::information(this,tr("Open Image"), tr("Already have an image opened"));
        return;
    }

    curFile = QFileDialog::getOpenFileName(this, tr("Open Image"),"",
                                           tr("PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;ALL files(*.*)"));
    if (curFile.isEmpty())
    {
        QMessageBox::information(this,tr("Open Image"), tr("Please select an image to open"));
        curFile = QFileDialog::getOpenFileName(this,tr("Open Image"),"",
                                               tr("PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;ALL files(*.*)"));
        return;
    }

    //Save File in (QImage img).
    if (!(img.load(curFile,0)))
    {
       QMessageBox::information(this,tr("Unable to open the Image"), tr("Please select a valid image."));
       return;
    }

    //show picture
    paint(curFile);
}

bool MainWindow::slotsaveFile()
{
    if (curFile.isEmpty())
    {
        QMessageBox::information(this,tr("No Image to Save"), tr("Please open an image."));
        return false;
    }
    else
    {
        return slotsaveAs();
    }
}

bool MainWindow::slotsaveAs()
{
    QFileDialog dialog(centralWidget);
    QStringList files;

    dialog.setWindowTitle(tr("Save As"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Image Files(*.jpg *.png)"));

    if (dialog.exec())
    {
        files = dialog.selectedFiles();
    }
    else
    {
        return false;
    }

    return savePic(files.at(0));
}
