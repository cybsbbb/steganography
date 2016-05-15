#include "mainwindow.h"
#include "algorithm.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QTabWidget>
#include <QBrush>
#include <QMdiArea>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    createToolbars();
    createButtons();
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paint(const QString &filename)
{
    //centralWidget = new QMdiSubWindow(ui->widget);
   // QImage img_current = QImage(img,ui->picWidget->width(),ui->picWidget->height(),QImage::Format_RGB888);
    QPixmap pixmap=QPixmap::fromImage(img);
    cout<<"paint do"<<endl;
    view = new QGraphicsView(ui->picWidget);
    QGraphicsScene *scene = new QGraphicsScene;

    scene->addPixmap(pixmap);
    view->setWindowTitle(filename);
    view->setFixedSize(ui->picWidget->width(),ui->picWidget->height());
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

    steAct = new QAction(tr("Do Steganography"), this);
    steAct->setStatusTip(tr("Do Steganography with the picture opened"));
    connect(steAct,SIGNAL(triggered()),this,SLOT(on_steButton_clicked()));
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

    steMenu = menuBar()->addMenu(tr("Steganography"));
    steMenu->addAction(steAct);
}

void MainWindow::createToolbars()
{
    toolbar_ = this->addToolBar(tr("Main ToolBar"));
    toolbar_->addAction(openAct);
    toolbar_->addAction(saveAct);

    statusBar();
}

void MainWindow::createButtons()
{
    ui->steButton->addAction(steAct);
}

void MainWindow::closeEvent()
{

}

bool MainWindow::savePic(const QString &fileName)
{
    if(!(img_after_ste.save(fileName)))
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
    QMessageBox::about(this, tr("About Steganography"),tr("The <b>Steganography</b>"
                                                          "is a program using Steganography to encrypt pictures"));
}

void MainWindow::slotopenFile()
{
    //if there is an image have already been opened,RETURN.
    if (!(curFile.isEmpty()))
    {
        QMessageBox::information(this, tr("Open Image"), tr("Already have an image opened"));
        return;
    }

    curFile = QFileDialog::getOpenFileName(this, tr("Open Image"),"",
                                           tr("PNG(*.png);;BMP(*.bmp);;JPG(*.jpg);;ALL files(*.*)"));
    if (curFile.isEmpty())
    {
        QMessageBox::information(this, tr("Open Image"), tr("Have NOT select an image to open!"));
        return;
    }

    //Save File in (QImage img).
    if (!(img.load(curFile,0)))
    {
       QMessageBox::information(this,tr("Unable to open the Image"), tr("Please select a valid image."));
       return;
    }
	else
	{
		img_after_ste = img;//��ֹ����ͼƬʱû�ж�ͼƬ����������img_after_steΪ�գ�
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
    QFileDialog dialog(ui->picWidget);
    QStringList files;

    dialog.setWindowTitle(tr("Save As"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Image Files(*.png)"));

    if (dialog.exec())
    {
        files = dialog.selectedFiles();

        //create director
        /*QDir *temp = new QDir;
        bool exist = temp->exists("D://temp");
        if(exist)
        {
           QMessageBox::warning(this,tr("?????"),tr("????????"));
        }
        else
        {
           bool ok = temp->mkdir("D://temp");
           if( ok )
           {
              QMessageBox::warning(this,tr("?????"),tr("????????"));
           }
        }*/
    }
    else
    {
        return false;
    }

    return savePic(files.at(0));
}

void MainWindow::slotclose()
{

}

void MainWindow::on_steButton_clicked()
{
    if (curFile.isEmpty())
    {
        QMessageBox::information(this, tr("No Image to Steganography"), tr("Please open an image."));
    }
    else
    {
        ste_Algo = new Algorithm(img);
        QString inputText = ui->inputEdit->text();
        ste_Algo->EmbedText(inputText);
		img_after_ste = ste_Algo->img;
    }
	QPixmap pixmap = QPixmap::fromImage(ste_Algo->img);
	QGraphicsScene *scene = new QGraphicsScene;

	scene->addPixmap(pixmap);
	view->setScene(scene);
	view->show();
	delete ste_Algo;

    statusBar()->showMessage(tr("Steganography finished!"), 2000);
    return;

}

void MainWindow::on_showButton_clicked()
{
    if (curFile.isEmpty())
    {
        QMessageBox::information(this,tr("No Image to Steganography"), tr("Please open an image."));
        return;
    }
    else
    {
        ste_Algo = new Algorithm(img_after_ste);
        ste_Algo->ExtractText();
        QString result = ste_Algo->resultSte;

		for (int i = 0; i < result.size(); i++)
		{
			char cc = result.at(i).unicode();
			cout << cc;
		}
        cout << endl;
        ui->showBrowser->setText(result);
		delete ste_Algo;
        statusBar()->showMessage(tr("De-Steganography finished!"), 2000);
    }
}
