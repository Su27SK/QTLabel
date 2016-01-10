#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), label(new QLabel(this))
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delayShowLabel()
{
    label->update();
    label->clear();
    label->setWindowTitle("显示数据窗口");
    label->setGeometry(100, 100, 150, 150);
    label->setAlignment(Qt::AlignCenter);
    label->setText(this->_message);
    label->repaint();
}

void MainWindow::setLabelText(QString message)
{
    this->_message = message;
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(delayShowLabel()) );
    timer->start(1000);
}

void MainWindow::updateLabel()
{
    label->update();
}

void MainWindow::showLabel()
{
    label->show();
}

void MainWindow::repaintLabel()
{
    label->repaint();
}

myThread::myThread(string message)
{
    this->_message = QString::fromStdString(message);
}

void myThread::run()
{
     this->fakeMain();
}

void myThread::showMessage(string message)
{
    QString s = QString::fromStdString(message);
    emit   this->signalGUI(s);
    this->sleep(1);
 }

string myThread::ItoString(int source)
{
    stringstream ss;
    string str;
    ss<<source;
    ss>>str;
    return str;
}

void myThread::fakeMain()
{
    int i = 0;
     for (i = 0; i< 10; i++) {
         this->showMessage(this->ItoString(i));
     }
}





