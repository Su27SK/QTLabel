#include "mainwindow.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    myThread threadH("Hello World");
    QObject::connect(&threadH, SIGNAL(signalGUI(QString)), &w, SLOT(setLabelText(QString)));
    threadH.start();
    w.show();
    app.exec();
}

