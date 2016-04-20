#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QTabWidget>
#include <QBrush>
#include <QMdiArea>

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
    centralWidget->setWindowTitle(filename);
    centralWidget->activateWindow();
    centralWidget->resize(QSize(300,300));
    centralWidget->show();

    QPixmap pixmap=QPixmap::fromImage(img);
    pixmap = pixmap.scaled(centralWidget->size());
    centralWidget->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(centralWidget->backgroundRole(), QBrush(pixmap));
    centralWidget->setPalette(palette);
    centralWidget->repaint();
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
    connect(exitAct, SIGNAL(triggered()), this, SLOT(slotclose()));

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

void MainWindow::slotabout()
{
    QMessageBox::about(this, tr("About Steganography"),tr("The <b>Steganography</b>  "
                                                          "is a program using Steganography to encrypt pictures"));

}

void MainWindow::slotclose()
{

}

void MainWindow::slotopenFile()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"),"",
                                                   tr("PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;ALL files(*.*)"));
    if (filename.isEmpty())
    {
        QMessageBox::information(this,tr("Open Image"), tr("Please select an image to open"));
                                 filename=QFileDialog::getOpenFileName(this,tr("Open Image"),"",
                                                                       tr("PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;ALL files(*.*)"));
        return;
    }


    if (!(img.load(filename,0)))
    {
       QMessageBox::information(this,tr("Unable to open the Image"), tr("Please select a valid image."));
       return;
    }
    paint(filename);
}

void MainWindow::slotsaveFile()
{

}
